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

bool LoadList(Topic& mainTopic)
{
	if (fs::exists("DATA"))
	{
		std::vector<File> files = GetFilesInDir("DATA");
		for (size_t i = 0; i < files.size(); i++) {
		std::cout << files[i].GetName() << " " << files[i].GetPath() << '\n';
		}
		std::vector<Topic> topics = GetDirsInDir("DATA");
		for (size_t i = 0; i < topics.size(); i++) {
			std::cout << topics[i].GetName() << '\n';
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