#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Snake.h"
#include "Point.h"

using namespace std;

//#define FOREGROUND_BLUE      0x0001 // text color contains blue.
//#define FOREGROUND_GREEN     0x0002 // text color contains green.
//#define FOREGROUND_RED       0x0004 // text color contains red.
//#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
//#define BACKGROUND_BLUE      0x0010 // background color contains blue.
//#define BACKGROUND_GREEN     0x0020 // background color contains green.
//#define BACKGROUND_RED       0x0040 // background color contains red.
//#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Snake::Snake() {
	size = 1;
	cell[0] = new Point(20, 20); 

	for (int i = 1; i < MAXSNAKESIZE; i++) {
		cell[i] = NULL;
	}

	fruit.setPoint( (rand() % MAXFRAMEX) , (rand() % MAXFRAMEY) );
	state = false;
	started = false;
}


// Add a new cell to the snake at the specified position (x, y)
void Snake::AddCell(int x, int y) {
	cell[size++] = new Point(x, y);
}


// Change the snake's direction to up (if it's not currently moving down)
void Snake::TurnUp() {
	if (dir != 's')
		dir = 'w';
}


// Change the snake's direction to down (if it's not currently moving up)
void Snake::TurnDown() {
	if (dir != 'w')
		dir = 's';	
}


// Change the snake's direction to right (if it's not currently moving left)
void Snake::TurnRight() {
	if (dir != 'a')
		dir = 'd';	
}

// Change the snake's direction to left (if it's not currently moving right)
void Snake::TurnLeft() {
	if (dir != 'd')
		dir = 'a';	
}


// Display a welcome screen with a specific color scheme
void Snake::WelcomeScreen() {

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	cout << "\n            (c)Shahar Shemesh                                 ";
	cout << "\n    --..,_                     _,.--.                         ";
	cout << "\n       `'.'.                .'`__ o  `;__.                    ";
	cout << "\n          '.'.            .'.'`  '---'`  `                    ";
	cout << "\n            '.`'--....--'`.'                                  ";
	cout << "\n              `'--....--'`                                    ";
	cout << "\n\n\n";

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
}


void Snake::Move() {
	
	system("cls");


	if (!state)
	{
		if (!started)
		{
			WelcomeScreen();
			cout << "Press any key to start.\n";
			_getch();
			started = true;
			state = true;
		}
		else {
			cout << "Game Over!\n";
			cout << "Press any key to start.\n";
			_getch();
			state = true;
			size = 1;
		}

	}

	
	for (int i = size-1; i > 0; i--){
		cell[i-1]->CopyPos(cell[i]);
	}

	switch (dir){
		case 'w':
			cell[0]->MoveUp();
			break;
		case 's':
			cell[0]->MoveDown();
			break;
		case 'a':
			cell[0]->MoveLeft();
			break;
		case 'd':
			cell[0]->MoveRight();
			break;
	}

	if ( SefCollision() ) {
		state = false;
	}


	if ( (fruit.GetX() == cell[0]->GetX())  &&  (fruit.GetY() == cell[0]->GetY()) )
	{
		AddCell(0, 0);
		fruit.setPoint((rand() % MAXFRAMEX), (rand() % MAXFRAMEY));
	}


	for (int i = 0; i < size; i++){		
		cell[i]->Draw();
	}


	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	fruit.Draw('$');
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);

	Sleep(50);
}


// Check if the snake collides with itself
int Snake::SefCollision() {
	for (int i = 1; i < size; i++){
		if (	cell[0]->IsEqual(cell[i])	) 
			return 1;	
	}
	return 0;	
}
