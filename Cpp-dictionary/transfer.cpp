#include "transfer.h"
#include "explorer.h"

int HandleCommand(std::vector<std::string> command)
{
	if (command[0] == "help")
	{
		Help();
		return 0;
	}
	if (command[0] == "about")
	{
		About();
		return 0;
	}
	if (command[0] == "decor")
	{
		Decor();
		return 0;
	}
	if (command[0] == "list")
	{
		global::mainTopic.Print();
		std::cout << '\n';
		return 0;
	}
	if (command[0] == "create" && command.size() == 3)
	{
		if (command[1] == "topic")
		{
			std::string r = AddTopic(command[2]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]topic successfully created\n";
				global::mainTopic.ClearContext();
				if (!LoadList(global::mainTopic, "DATA"))
				{
					SetConsoleTextAttribute(global::hConsole, 4);
					printf("[!]error to update list data\n");
				}
			}
			else 
			{
				SetConsoleTextAttribute(global::hConsole, 4);
				std::cout << "[!]"<<r<<'\n';
			}
		}
		else if (command[1] == "doc") 
		{
			std::string r = AddDoc(command[2]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]doc successfully created\n";
				global::mainTopic.ClearContext();
				if (!LoadList(global::mainTopic, "DATA"))
				{
					SetConsoleTextAttribute(global::hConsole, 4);
					printf("[!]error to update list data\n");
				}
			}
			else
			{
				SetConsoleTextAttribute(global::hConsole, 4);
				std::cout << "[!]" << r << '\n';
			}
		}
		else
			return 1;
		return 0;
	}
	else
	{
		return 1;
	}
}


std::vector<std::string> Split(const std::string& input, const std::string& separator)
{
	std::vector<std::string> result;
	size_t start = 0;
	size_t end = 0;

	while ((end = input.find(separator, start)) != std::string::npos)
	{
		result.push_back(input.substr(start, end - start));
		start = end + separator.length();
	}

	result.push_back(input.substr(start));

	return result;
}