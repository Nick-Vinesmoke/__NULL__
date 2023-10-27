#pragma once
#include "main.h"
#include "setup.h"

namespace global
{
    inline HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    inline std::string user = GetUser();
    inline std::string logo = R"LOGO(  ___ ___ ___     ___  _    _   _                        
 / __| _ \ _ \___|   \(_)__| |_(_)___ _ _  __ _ _ _ _  _ 
| (__|  _/  _/___| |) | / _|  _| / _ \ ' \/ _` | '_| || |
 \___|_| |_|     |___/|_\__|\__|_\___/_||_\__,_|_|  \_, |
                                                    |__/ )LOGO";
}