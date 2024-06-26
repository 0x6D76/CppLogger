/*
 ***********************************************************************************************************************
 * File: logger.cpp
 * Description: This file contains definitions support functions & member functions associated with logging 
 *              functionalities.
 * Functions:
 *           string GetReturnMessage ()
 * Author: 0x6D76
 * Copyright (c) 2024 0x6D76 (0x6D76@proton.me)
 ***********************************************************************************************************************
 */
#include "logger.hpp"
#include "tool.hpp"

std::string GetReturnMessage (ReturnCodes returnCode) {

    auto find = ReturnMessages.find (returnCode);
    return (find != ReturnMessages.end ()) ? find->second : UNKNOWN;
} /* End of GetReturnMessage () */

