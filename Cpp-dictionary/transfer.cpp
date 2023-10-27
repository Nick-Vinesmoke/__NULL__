#include "transfer.h"

int HandleCommand(std::string command)
{
	if (command == "help")
	{
		Help();
		return 0;
	}
	if (command == "about")
	{
		About();
		return 0;
	}
	if (command == "decor")
	{
		Decor();
		return 0;
	}
	if (command == "list")
	{
		global::mainTopic.Print();
		std::cout << '\n';
		return 0;
	}
	else
	{
		return 1;
	}
}