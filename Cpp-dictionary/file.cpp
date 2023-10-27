#include "file.h"


File::File(const std::string& fileName, const std::string& filePath)
{
	this->name = fileName;
	this->path = filePath;
}

File::~File()
{
}


std::string File::GetName() { return this->name; }
std::string File::GetPath() { return this->path; }