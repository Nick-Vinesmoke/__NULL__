#pragma once
#include "main.h"
#include "setup.h"
#include "topic.h"

std::string GetUser();

namespace global
{
    struct style
    {
        std::string name;
        int index;
    };

    inline std::vector<style> styles = 
    {
    {"blue: ", 9},
    {"green: ", 2},
    {"light blue: ", 3},
    {"red: ", 4},
    {"yellow: ", 6},
    {"white: ", 7},
    {"grey: ", 8},
    {"purple: ", 5},
    {"normal: ", 7},
    {"highlight: ", 96}
    };

    inline bool codeFrame = false;
    inline HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    inline std::string user = GetUser();
    inline Topic mainTopic("DATA", "DATA");
    inline std::string logo = R"LOGO(  ___ ___ ___     ___  _    _   _                        
 / __| _ \ _ \___|   \(_)__| |_(_)___ _ _  __ _ _ _ _  _ 
| (__|  _/  _/___| |) | / _|  _| / _ \ ' \/ _` | '_| || |
 \___|_| |_|     |___/|_\__|\__|_\___/_||_\__,_|_|  \_, |
                                                    |__/ )LOGO";
}