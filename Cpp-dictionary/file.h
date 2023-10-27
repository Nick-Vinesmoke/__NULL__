#pragma once
#include "main.h"

class File
{
public:
	File(const std::string& fileName, const std::string& filePath);
	~File();
	std::string GetName();
	std::string GetPath();

private:
	std::string name;
	std::string path;
};
