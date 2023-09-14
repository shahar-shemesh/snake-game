#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <stdio.h>
#include <string>

#include "Point.h"
#include "Snake.h"

using namespace std;

int main() {

	srand((unsigned)time(NULL));

	Snake snake;
	char op = 'l';

	do
	{
		if (_kbhit()){	
			op = _getch();
		}

		switch (op){
			case 'w':
			case 'W':
				snake.TurnUp();
				break;
			case 's':
			case 'S':
				snake.TurnDown();
				break;
			case 'a':
			case 'A':
				snake.TurnLeft();
				break;
			case 'd':
			case 'D':
				snake.TurnRight();
				break;
		}

		snake.Move();

	} while (op != 'e');


	cout << "\n\n";

	return 0;
}