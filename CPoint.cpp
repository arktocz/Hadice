#include "stdafx.h"
#include "CPoint.h"


CPoint::CPoint()
{
	x = y = 10;
}

CPoint::CPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CPoint::SetPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

int CPoint::GetX()
{
	return x;
}

int CPoint::GetY()
{
	return y;
}

void CPoint::MoveUp()
{
	y--;
}

void CPoint::MoveDown()
{
	y++;
}

void CPoint::MoveLeft()
{
	x--;
}

void CPoint::MoveRight()
{
	x++;
}

void CPoint::Draw()
{
	PrintXY(x, y, "*");
}

void CPoint::Erase()
{
	PrintXY(x, y, " ");
}

void CPoint::CopyPos(CPoint* p)
{
	p->x = x;
	p->y = y;
}

void CPoint::Debug()
{
	
	//cout << "(" << x << "," << y << ") ";
}
