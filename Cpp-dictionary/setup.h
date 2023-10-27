#pragma once
#include "main.h"
#include <Lmcons.h>
#include <filesystem>
#include "file.h"
#include "topic.h"
#include "explorer.h"
#include "global.h"


void Setup();
std::string GetUser();
bool LoadList(Topic& mainTopic, const std::string& path);