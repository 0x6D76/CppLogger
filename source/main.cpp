/*
 ***********************************************************************************************************************
 * File: main.cpp
 * Description:
 * Functions:
 * Author: 0x6D76
 * Copyright (c) 2024 0x6D76 (0x6D76@proton.me)
 ***********************************************************************************************************************
 */

#include "logger.hpp"

int main () {
    std::stringstream opt {};
    opt << "This is an optional message.";
    Logger l ("temp.log", false);
    l.Header ();
    l.Log (PASS, MOD_INIT, INIT_PASS, true);
    l.Log (FAIL, MOD_INIT, INIT_FAIL, true);
    l.Log (INFO, MOD_CLEAN, INIT_PASS, true);
    l.Footer ();
}