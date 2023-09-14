#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Point.h"
#include "Snake.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}


// Function to set the cursor position
void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}


// Constructor for Point class, initializes with default position
Point::Point() {
	setcursor(0, 0);
	x = y = 10;
}


// Constructor for Point class, initializes with provided position
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}


// Set the position of the Point
void Point::setPoint(int x, int y) {
	this->x = x;
	this->y = y;
}


// Get the X coordinate of the Point
int Point::GetX() {
	return x;
}


// Get the Y coordinate of the Point
int Point::GetY() {
	return y;
}


// Move the Point up (decrease Y coordinate)
void Point::MoveUp() {
	y--;
	if (y < 0)
		y = MAXFRAMEY;
}


// Move the Point down (increase Y coordinate)
void Point::MoveDown() {
	y++;
	if (y > MAXFRAMEY)
		y = 0;
}


// Move the Point left (decrease X coordinate)
void Point::MoveLeft() {
	x--;
	if (x < 0)
		x = MAXFRAMEX;
}


// Move the Point right (increase X coordinate)
void Point::MoveRight() {
	x++;
	if (x > MAXFRAMEX)
		x = 0;
}


// Print the coordinates of the Point for debugging
void Point::Draw(char c) {
	gotoxy(x, y);
	if (c != 'O')
		SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << c;
}


// Erase the Point from its current position
void Point::Erase() {
	gotoxy(x, y);
	cout << " ";
}


// Copy the position of this Point to another Point
void Point::CopyPos(Point* p) {
	p->x = x;
	p->y = y;
}


// Check if this Point is equal to another Point
int Point::IsEqual(Point* p) {
	if ( p->x == x  &&  p->y == y )
		return 1;
	return 0;
}


// Print the coordinates of the Point for debugging
void Point::Debug() {
	cout << "(" << x << "," << y << ") ";
}