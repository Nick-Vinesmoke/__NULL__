#include "file.h"


File::File(const std::string& fileName, const std::string& filePath)
{
	this->name = fileName;
	this->path = filePath;
}

File::~File()
{
}


std::string File::GetName() const { return this->name; }
std::string File::GetPath() const { return this->path; }