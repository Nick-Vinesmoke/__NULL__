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
			return 0;
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
			return 0;
		}
		else
			return 1;
	}
	if (command[0] == "delete" && command.size() == 2)
	{
		if (command[1] == "topic" && command.size() == 3)
		{
			std::string r = DelTopic(command[2]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]topic successfully deleted\n";
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
			return 0;
		}
		if (command[1] == "doc" && command.size() == 3)
		{
			std::string r = DelDoc(command[2]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]doc successfully deleted\n";
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
			return 0;
		}
		if (command[1] == "all")
		{
			std::string r = DelTopic("DATA");
			SetConsoleTextAttribute(global::hConsole, 6);
			std::cout << "[i]DATA successfully deleted\n";
			global::mainTopic.ClearContext();
			try
			{
				fs::create_directory("DATA");
			}
			catch (...){}
			return 0;
		}
		else
			return 1;
	}
	if (command[0] == "change" && command.size() == 4)
	{
		if (command[1] == "topic") 
		{
			std::string r = RenameTopic(command[2], command[3]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]topic successfully renamed\n";
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
			return 0;
		}
		else if (command[1] == "doc") 
		{
			std::string r = RenameDoc(command[2], command[3]);
			if (r == "done")
			{
				SetConsoleTextAttribute(global::hConsole, 6);
				std::cout << "[i]doc successfully renamed\n";
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
			return 0;
		}
		else
			return 1;
	}
	else
		return 1;
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