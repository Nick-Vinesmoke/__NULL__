#include "helper.h"
#include <Lmcons.h>

std::string GetUser()
{
	TCHAR s[UNLEN + 1];
	DWORD sizethis = UNLEN + 1;
	GetUserName((TCHAR*)s, &sizethis);
	std::wstring ws(s);
	std::string userName(ws.begin(), ws.end());
	return userName;
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


void toLower(std::string& line) 
{
	for (char& c : line)
	{
		c = tolower(c);
	}
}