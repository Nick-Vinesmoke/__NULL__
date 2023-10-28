#include "transfer.h"
#include "explorer.h"


void PrintSearchResults(const std::vector<std::variant<File, Topic>>& results)
{
	if (results.empty()) 
	{
		SetConsoleTextAttribute(global::hConsole, 6);
		std::cout << "[i]no matches" << std::endl;
		return;
	}

	SetConsoleTextAttribute(global::hConsole, 6);
	std::cout << "[i]searching results:" << std::endl;

	for (size_t i = 0; i < results.size(); i++)
	{
		if (std::holds_alternative<File>(results[i])) {
			const File& file = std::get<File>(results[i]);
			SetConsoleTextAttribute(global::hConsole, 8);
			printf("   %d.%s\n", i, file.GetName().c_str());
		}
		else if (std::holds_alternative<Topic>(results[i])) {
			const Topic& topic = std::get<Topic>(results[i]);
			SetConsoleTextAttribute(global::hConsole, 9);
			printf("   %d.%s\n", i, topic.GetName().c_str());
		}
	}
}

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
	if (command[0] == "redact" && command.size() == 2) 
	{
		std::string r = OpenInEditor(command[1]);
		if (r == "done")
		{
			SetConsoleTextAttribute(global::hConsole, 6);
			std::cout << "[i]doc successfully opened in the editor\n";
		}
		else
		{
			SetConsoleTextAttribute(global::hConsole, 4);
			std::cout << "[!]" << r << '\n';
		}
		return 0;
	}
	if (command[0] == "search" && command.size() == 2)
	{
		std::vector<std::variant<File, Topic>> results;
		global::mainTopic.Search(results, command[1]);
		PrintSearchResults(results);
		SetConsoleTextAttribute(global::hConsole, 6);
		std::cout << "[i]type \"details>index\" to see details\n";
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

				for (char& c : commandWords[0])
				{
					c = tolower(c);
				}
				if (commandWords[0] == "details")
				{
					if (commandWords.size() == 2)
					{
						if (std::holds_alternative<File>(results[std::stoi(commandWords[1])]))
						{
							const File& file = std::get<File>(results[std::stoi(commandWords[1])]);
							//read file by path

						}
						else if (std::holds_alternative<Topic>(results[std::stoi(commandWords[1])]))
						{
							const Topic& topic = std::get<Topic>(results[std::stoi(commandWords[1])]);
							topic.Print();
							//choose doc in topic to read
						}
					}
					else 
					{
						SetConsoleTextAttribute(global::hConsole, 4);
						std::cout << "[!]invalid command\n";
					}
				}
				else
				{
					int r = HandleCommand(commandWords);
					if (r == 1)
					{
						SetConsoleTextAttribute(global::hConsole, 4);
						std::cout << "[!]invalid command\n";
						return 0;
					}
				}
			}
		}
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