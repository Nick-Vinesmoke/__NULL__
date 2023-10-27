#pragma once
#include "main.h"
#include "global.h"

int HandleCommand(std::vector<std::string> command);

void Help();

void About();

void Decor();

std::vector<std::string> Split(const std::string& input, const std::string& separator);
