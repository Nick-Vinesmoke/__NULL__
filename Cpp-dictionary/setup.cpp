#include "setup.h"


namespace fs = std::filesystem;

void Setup() 
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	FlushConsoleInputBuffer(global::hConsole);
	SetConsoleTextAttribute(global::hConsole, 9);
	HWND hWindowConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(hWindowConsole, &r);
	MoveWindow(hWindowConsole, r.left, r.top, 900, 520, TRUE);
}

std::string GetUser() 
{
	TCHAR s[UNLEN + 1];
	DWORD sizethis = UNLEN + 1;
	GetUserName((TCHAR*)s, &sizethis);
	std::wstring ws(s);
	std::string userName(ws.begin(), ws.end());
	return userName;
}

bool LoadList(Topic& mainTopic, const std::string& path)
{
	if (fs::exists("DATA"))
	{
		std::vector<File> files;
		std::vector<Topic> topics;
		files = GetFilesInDir(path);
		topics = GetDirsInDir(path);
		for (size_t i = 0; i < files.size(); i++)
		{
			mainTopic.AddContext(files[i]);
		}
		for (size_t i = 0; i < topics.size(); i++) 
		{
			LoadList(topics[i], path+'/'+ topics[i].GetName());
			mainTopic.AddContext(topics[i]);
		}
		return true;
	}
	else
	{
		if (fs::create_directory("DATA"))
			return true;
		else
			return false;
	}
}