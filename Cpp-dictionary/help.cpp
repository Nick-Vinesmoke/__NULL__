#include "transfer.h"

void Help() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(help                           ===>   get the full list of available commands
about                          ===>   get info about this application as name, ver, etc
search                         ===>   search for topic or doc
decor                          ===>   receive instructions on how to prepare and work with the documentation file
list                           ===>   get a complete list of topics and their docs
create>topic/doc>path          ===>   create a topic or doc, path should looks like DATA/topik_1/.../name
delete>topic/doc>path          ===>   delete a topic or doc, path should looks like DATA/topik_1/.../name
change>topic/doc>path>new name ===>   change a topic name or doc name, path should looks like DATA/topik_1/.../name
redact>path                    ===>   redact a doc, path should looks like DATA/topik_1/.../name)LOGO";
	printf("%s\n\n", commands.c_str());
}