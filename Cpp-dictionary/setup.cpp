#include "setup.h"
#include"global.h"

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