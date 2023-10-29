#include "main.h"
#include "setup.h"
#include "transfer.h"
#include "topic.h"
#include "helper.h"
#include "global.h"
#include "dictionary.h"

int main() 
{
	Setup();
	printf("%s\n", global::logo.c_str());
	printf("Welcome dear %s!!!\n", global::user.c_str());
	SetConsoleTextAttribute(global::hConsole, 6);
	printf("[i]type \"help\" to get commands list\n");
	if (!LoadList(global::mainTopic, "DATA"))
	{
		SetConsoleTextAttribute(global::hConsole, 4);
		printf("[!]error to load list data\n");
	}
	std::string command;
	while (true)
	{
		SetConsoleTextAttribute(global::hConsole, 2);
		printf(">>>");
		SetConsoleTextAttribute(global::hConsole, 8);
		getline(std::cin, command);
		if (!command.empty())
		{
			std::vector<std::string> commandWords = Split(command, ">");
			for (size_t i = 0; i < commandWords.size(); i++)
			{
				if (i<2)
				{
					toLower(commandWords[i]);
				}
			}
			int r = HandleCommand(commandWords);
			if (r == 1)
			{
				SetConsoleTextAttribute(global::hConsole, 4);
				std::cout << "[!]invalid command\n";
			}
		}
	}
	return 0;
}