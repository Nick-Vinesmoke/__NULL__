#pragma once
#include "main.h"
#include<vector>


std::string GetUser();
std::vector<std::string> Split(const std::string& input, const std::string& separator);
void toLower(std::string& line);