#pragma once
#include "main.h"
#include <Lmcons.h>
#include <filesystem>
#include "file.h"
#include "explorer.h"
#include "topic.h"

void Setup();
std::string GetUser();
bool LoadList(Topic& mainTopic);