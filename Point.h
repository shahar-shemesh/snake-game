#pragma once

#include <iostream>

using namespace std;

class Point{
	
public:
	Point();
	Point(int, int);
	void setPoint(int, int);
	int GetX();
	int GetY();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Draw(char c='O');
	void Erase();
	void CopyPos(Point*);
	int IsEqual(Point*);
	void Debug();

private:
	int x;
	int y;
};
