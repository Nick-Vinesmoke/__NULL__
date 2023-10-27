#include "main.h"
#include "setup.h"
#include "transfer.h"
#include "topic.h"

int main() 
{
	Setup();
	printf("%s\n", global::logo.c_str());
	printf("Welcome dear %s!!!\n", global::user.c_str());
	SetConsoleTextAttribute(global::hConsole, 6);
	printf("[i]type \"help\" to get commands list\n");
	Topic mainTopic("DATA");
	if (!LoadList(mainTopic))
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
			for (char& c : command) {
				c = tolower(c);
			}
			int r = HandleCommand(command);
			if (r == 1)
			{
				SetConsoleTextAttribute(global::hConsole, 4);
				std::cout << "[!]invalid command\n";
			}
		}
	}
	return 0;
}