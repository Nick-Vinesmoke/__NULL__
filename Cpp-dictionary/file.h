#pragma once
#include "main.h"

class File
{
public:
	File(const std::string& fileName, const std::string& filePath);
	~File();
	std::string GetName() const;
	std::string GetPath() const;

private:
	std::string name;
	std::string path;
};
