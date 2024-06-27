/*
 ***********************************************************************************************************************
 * File: tool.hpp
 * Description: This file contains macros, enums and other data structures associated with customizing tool information.
 * 
 * Author: 0x6D76
 * Copyright (c) 2024 0x6D76 (0x6D76@proton.me)
 ***********************************************************************************************************************
 */
#ifndef CPPLOGGER_TOOL_HPP
#define CPPLOGGER_TOOL_HPP
#include <map>
#include <string>
/*
 * Edit the following, on a per-tool basis
 */
/* Tool Header */
const std::string TOOL = "CPP Logger";
const std::string VER  = "1.0";

/* Modules */
const std::string MOD_INIT = "Initialization";
const std::string MOD_CLEAN = "Clean-up";

/* Return Codes */
enum ReturnCodes {
    INIT_FAIL = -1,
    INIT_PASS =  2,
};

/* Return Messages */
static std::map <ReturnCodes, std::string> ReturnMessages = {
    {INIT_FAIL, "Initialization has failed. "},
    {INIT_PASS, "Initialization completed. "},
};
#endif