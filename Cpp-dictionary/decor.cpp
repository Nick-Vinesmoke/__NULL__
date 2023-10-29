#include "transfer.h"
#include "global.h"

void Decor() 
{
	SetConsoleTextAttribute(global::hConsole, 8);
	std::string commands = R"LOGO(here is a list of all possible design techniques when working with documentation files

<style>                ===>   change the style of the text after the tag, should looks like <color>blue:
<style>normal:         ===>   reset the style to default(white text on black bg)
all available styles:
	* blue
	* green
	* light blue
	* red
	* yellow	
	* white
	* grey
	* purple
	* highlight
	* underline

<code>=Name-Cpp        ===>   code frame with code name and specified language, should take full line 
</code>                ===>   end code frame, should take full line )LOGO";
	printf("%s\n\n", commands.c_str());
}