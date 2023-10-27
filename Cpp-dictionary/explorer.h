#pragma once
#include "main.h"
#include <filesystem>
#include <vector>
#include "file.h"
#include "topic.h"
#include <fstream>

namespace fs = std::filesystem;

std::vector<File> GetFilesInDir(const std::string& directoryPath);
std::vector<Topic> GetDirsInDir(const std::string& directoryPath);
std::string AddTopic(const std::string& path);
std::string AddDoc(const std::string& path);
