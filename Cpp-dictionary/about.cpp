#include "transfer.h"

void About() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(Cpp-Dictionary
version 1.0.0.0 x86

Dictionary for structural data storage in the form of topics, subtopics, files.
In this case it is used to store C++ documentation, but can be used for something else.

This software is licensed under MIT.

Creator: Nick Vinesmoke)LOGO";
	printf("%s\n\n", commands.c_str());
}