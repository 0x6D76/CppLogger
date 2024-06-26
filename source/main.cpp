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
    std::cout << GetReturnMessage (INIT_FAIL) << std::endl;
    std::cout << GetReturnMessage (INIT_PASS) << std::endl;
}