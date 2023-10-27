#include "transfer.h"

void Help() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(help                           ===>   get the full list of available commands
about                          ===>   gets info about this application as name, ver, etc
search>name                    ===>   searchs for topic or doc
decor                          ===>   receives instructions on how to prepare and work with the documentation file
list                           ===>   gets a complete list of topics and their docs
create>topic/doc>path          ===>   creates a topic or doc, path should looks like DATA/topik_1/.../name
delete>topic/doc>path          ===>   deletes a topic or doc, path should looks like DATA/topik_1/.../name
delete>all                     ===>   deletes all
change>topic/doc>path>new name ===>   changes a topic name or doc name, path should looks like DATA/topik_1/.../name
redact>path                    ===>   redacts a doc, path should looks like DATA/topik_1/.../name
read>path                      ===>   reads a doc, path should looks like DATA/topik_1/.../name)LOGO";
	printf("%s\n\n", commands.c_str());
}