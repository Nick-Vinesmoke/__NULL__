#include "transfer.h"

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
	if (command[0] == "create")
	{
		if (command[0] == "topic")
		{

		}
		else if (command[0] == "doc") 
		{

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