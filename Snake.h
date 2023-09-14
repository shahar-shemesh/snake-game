#pragma once

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <dos.h>

#include "Point.h"

using namespace std;

#define MAXSNAKESIZE 100
#define MAXFRAMEX 119
#define MAXFRAMEY 29

class Snake{

public:
	Snake();
	void AddCell(int, int);
	void TurnUp();
	void TurnDown();
	void TurnRight();
	void TurnLeft();
	void WelcomeScreen();
	void Move();
	int SefCollision();
	
private:
	Point* cell[MAXSNAKESIZE];	
	int size;	
	char dir;
	Point fruit;
	bool state;
	bool started;

};

