#pragma once
#include "main.h"
#include <filesystem>
#include <vector>
#include "file.h"
#include "topic.h"

namespace fs = std::filesystem;

std::vector<File> GetFilesInDir(const std::string& directoryPath);
std::vector<Topic> GetDirsInDir(const std::string& directoryPath);
