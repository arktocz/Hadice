#pragma once
#include "printxy.h"
#include "pozice.h"
class CPoint
{
private:
	int x;
	int y;
public:
	CPoint();
	
	CPoint(int x, int y);
	void SetPoint(int x, int y);
	int GetX();
	int GetY();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Draw();
	void Erase();
	void CopyPos(CPoint* p);
	void Debug();
};

