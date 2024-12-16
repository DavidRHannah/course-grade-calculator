#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

class Menu {
private:
	unsigned int optionCount;
public:
	Menu(unsigned int optionCount) : optionCount(optionCount) {};
	void menu(int selection) {
		std::system("CLS");
		unsigned int i = 1; int y; int xy = 3;
		while (i <= this->optionCount) {
			if (i == selection)
				y = i;
			else
				y = 0;
			xy = i;
			switch (xy) {
			case 1: print("1. Add Data", y); break;
			case 2: print("2. Display", y); break;
			case 3: print("3. Save", y); break;
			case 4: print("4. Load", y); break;
			case 5: print("5. Exit", y); break;
			default: break;
			}
			i++;
		}
	}
	void print(std::string label, bool x) {
		HANDLE console; 
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		byte labelColor = 15;
		if (x)
			labelColor = 240;
		SetConsoleTextAttribute(console, labelColor);
		std::cout << label << std::endl;

		SetConsoleTextAttribute(console, 15);
	}
};