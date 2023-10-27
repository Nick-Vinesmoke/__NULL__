#include "transfer.h"

void Decor() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(here is a list of all possible design techniques when working with documentation files

<color>     ===>   change the color of the text after the tag.
<normal>    ===>   reset the color to white
all available colors:
	* blue
	* green
	* light blue
	* red
	* yellow	
	* white
	* grey
	* purple

<highlight> ===>   highlight the text
<normal>    ===>   to reset

<code>=Cpp  ===>   code frame with specified language
</code> to  ===>   end code frame)LOGO";
	printf("%s\n\n", commands.c_str());
}