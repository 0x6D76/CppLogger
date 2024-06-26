/*
 ***********************************************************************************************************************
 * File: logger.hpp
 * Description: This file contains declarations of constants, support functions, classes & member functions associated
 *              with logging functionalities.
 * 
 * Author: 0x6D76
 * Copyright (c) 2024 0x6D76 (0x6D76@proton.me)
 ***********************************************************************************************************************
 */
#ifndef CPPLOGGER_LOGGER_HPP
#define CPPLOGGER_LOGGER_HPP
#include <ctime>
#include <iostream>
#include <string>
#include "tool.hpp"
/* Constant Declarations */
const int PASS =  1000;
const int FAIL = -1000;
const int INFO =  0;
/* Color codes */
const std::string RST = "\x1B[00m";
const std::string RED = "\x1B[31m";
const std::string GRN = "\x1B[32m";
const std::string YEL = "\x1B[33m";
const std::string BLU = "\x1B[34m";
const std::string MAG = "\x1B[35m";
const std::string CYN = "\x1B[36m";
const std::string UNKNOWN = "Ran into an unkown error.";
const std::string HEADER = TOOL + VER;
const std::string FOOTER = "Exiting the tool";
const std::string LINE = "=============================================================================================="
                         "==========================";
/* Logger class */

/* Function Declarations */
std::string GetReturnMessage (ReturnCodes code);
#endif