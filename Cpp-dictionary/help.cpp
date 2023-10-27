#include "transfer.h"

void Help() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(help   ===>   get the full list of available commands
about  ===>   get info about this application as name, ver, etc
search ===>   search for topic or doc
decor  ===>   receive instructions on how to prepare and work with the documentation file
list   ===>   get a complete list of topics and their docs
create ===>   create a topic or doc
delete ===>   delete a topic or doc
change ===>   change a topic name or doc name
redact ===>   redact a doc)LOGO";
	printf("%s\n\n", commands.c_str());
}