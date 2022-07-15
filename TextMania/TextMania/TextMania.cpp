#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 100; i++)
		std::cout << i << std::endl;
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
	ClearScreen();
   	if (argc == 0)
	{
		// запуск обработчика окна 
		// отображение стартовой надписи
		// призыв к началу ввода текста
		// после ввода начало обычной работы
	}
	else
	{

	}
	int a;
	std::cin >> a;
}

