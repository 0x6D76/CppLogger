/*
 ***********************************************************************************************************************
 * File: logger.cpp
 * Description: This file contains definitions support functions & member functions associated with logging 
 *              functionalities.
 * Functions:
 *           string GetReturnMessage ()
 *           string GetCurrentTime ()
 *           void InitializeDirectories ()
 *           class Logger
 *              Logger ()
 *              Header ()
 *              Footer ()
 *              Log ()
 * 
 * Author: 0x6D76
 * Copyright (c) 2024 0x6D76 (0x6D76@proton.me)
 ***********************************************************************************************************************
 */
#include "logger.hpp"
#include "tool.hpp"


/*
 * This function enumerates the ReturnMessages map structure and returns the message mapped to the given return code.
 * :arg: returnCode, ReturnCodes value indicating the integer value for the message to be fetched.
 * :return: string holding the return message associated with the given code, returns UNKNOWN if code is not found.
 */
const std::string GetReturnMessage (ReturnCodes returnCode) {

    auto find = ReturnMessages.find (returnCode);
    return (find != ReturnMessages.end ()) ? find->second : UNKNOWN;
} /* End of GetReturnMessage () */


/*
 * This function gets the current time, formats it to the required format using strftime and then returns it.
 * :return: string holding the current time in the "%d-%m-%y %H:%M:%S" format.
 */
const std::string GetCurrentTime () {

    time_t now = time (nullptr);
    char timeStamp [21];
    strftime (timeStamp, sizeof (timeStamp), "[%d-%m-%y %H:%M:%S]", localtime (&now));
    return (timeStamp);
} /* End of GetCurrentTime () */


/*
 *
 */
void InitializeDirectories (const std::vector <std::string>& dirs) {

    for (const auto &dir : dirs) {
        try {
            if (std::filesystem::exists (dir)) {
                std::cout << "Dir " << dir << " already exists.\n";
            } else if (std::filesystem::create_directory (dir)) {
                std::cout << "Dir " << dir << " created.\n";
            }
        } catch (const std::filesystem::filesystem_error &error) {
            std::cout << "Dir " << dir << " creation failed. Error: " << error.what () << std::endl;
        }
    }
} /* End of InitializeDirectories */


/*
 * This is a constructor function for Logger class.
 */
Logger::Logger (std::string nameFile, bool flag) : fileName (nameFile), verbose (flag) {
    
} /* End of Logger () */


/*
 * This function formats and prints header to both STDOUT and log file, based on user inputs on tool.hpp.
 * :arg: identifier, string holding the user-supplied identifier, to be printed onto log file. If identifier is
 *       not given, current time is used.
 */
void Logger::Header (const std::string identifier) {

    int padding = 0;
    std::stringstream opHeader {};
    std::stringstream flHeader {};
    std::string head = TOOL;
    std::ofstream logFile;
    if (!VER.empty ()) {
         head = head + " (" + VER + ")"; 
    }
    padding = (WIDTH - head.length ()) / 2;
    opHeader << LINE << "\n" << CYN << std::setw (padding + head.length ()) << head << RST << "\n" 
             << LINE << std::endl;

    flHeader << LINE << "\n" << std::setw (padding + identifier.length ()) << identifier << "\n" << LINE << std::endl;
    std::cout << opHeader.str ();
    logFile.open (fileName, std::ios::app);
    logFile << flHeader.str ();
    logFile.close ();
} /* End of Header () */


/*
 * This function formats and prints footer to both STDOUT and log file
 */
void Logger::Footer () {

    int padding = 0;
    std::stringstream foot {};
    std::ofstream logFile;
    padding = (WIDTH - FOOTER.length ()) / 2;
    foot << LINE << "\n" << std::setw (padding + FOOTER.length ()) << FOOTER << "\n" << LINE << std::endl;
    std::cout << foot.str ();
    logFile.open (fileName, std::ios::app);
    logFile << foot.str ();
    logFile.close ();

} /* End of Footer () */


/*
 * This function initially formats the log message based on the arguments given. The formatted log message is then
 * printed to the STDOUT, if either verbose or user flag is set to true. Finally the log message, sans-color is 
 * written to the log file, the instance is initated with.
 */
void Logger::Log (const int severity, const std::string module, const int code, bool uFlag, 
                  const std::stringstream& optional) {

    std::string color;
    std::string strType;
    std::string message;
    std::stringstream strUser;
    std::stringstream strFile;
    std::ofstream logFile;

    message = GetReturnMessage (static_cast<ReturnCodes> (code));
    switch (severity) {
        case PASS:
            color = GRN;
            strType = "[PASS]";
            break;
        case FAIL:
            color = RED;
            strType = "[FAIL]";
            break;
        case INFO:
            color = YEL;
            strType = "[INFO]";
            break;
    }

    if (verbose || uFlag) {
        strUser << color << strType << RST << GetCurrentTime () << "[" << module << "]" << message;
        if (optional) { strUser << optional.str (); }
        std::cout << strUser.str () << std::endl;
    }

    strFile << strType << GetCurrentTime () << "[" << module << "]" << message;
    if (optional) { strFile << optional.str (); }
    strFile << "\n";
    logFile.open (fileName, std::ios::app);
    logFile << strFile.str ();
    logFile.close ();
} /* End of Log () */