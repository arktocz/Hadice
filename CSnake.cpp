#include "stdafx.h"
#include "CSnake.h"

CSnake::CSnake()
{
	size = 1; // default size
	cell[0] = new CPoint(20, 20); // 20,20 is default position
	for (int i = 1; i < MAXSIZE; i++) {
		cell[i] = NULL;
	}
	fruit.SetPoint((rand() % (100-2+1)+1), (rand() % (29 - 2 + 1) + 1));
}

void CSnake::AddCell(int x, int y)
{
	
	cell[size++] = new CPoint(x, y);
	
}

void CSnake::TurnUp()
{
	dir = 'w';
}

void CSnake::TurnDown()
{
	dir = 's';
}

void CSnake::TurnLeft()
{
	dir = 'a';
}

void CSnake::TurnRight()
{
	dir = 'd';
}

bool CSnake::Move()
{
	CPoint *temp=cell[size-1];
	temp->Erase();
	bool food = false;
	// making snake body follow its head
	for (int i = size - 1; i > 0; i--) {
		cell[i - 1]->CopyPos(cell[i]);
		
	}

	// turning snake's head
	switch (dir) {
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
	
	// Collision with fruit
	if (fruit.GetX() == cell[0]->GetX() && fruit.GetY() == cell[0]->GetY()) {
		AddCell(0, 0);
		food = true;
		Beep(1000, 50);
		fruit.SetPoint((rand() % (100 - 2 + 1) + 1), (rand() % (29 - 2 + 1) + 1));//rand generator pozice
	}

	//drawing snake
	for (int i = 0; i < size; i++) {
		cell[i]->Draw();
	}
	
	
	fruit.Draw();

	//Debug();

	Sleep(50);
	return food;
}

bool CSnake::BodyCheck()//predelat na navrat flase
{
	
	for (size_t i = 1; i < size; i++)
	{
		if (cell[0]->GetX() == cell[i]->GetX() && cell[0]->GetY() == cell[i]->GetY())
			return true;
	}
	return false;
	
}

bool CSnake::BorderCheck()
{
	
		if (cell[0]->GetX() == 0 || cell[0]->GetX() == 100 || cell[0]->GetY() == 0 || cell[0]->GetY() == 29)
			return true;
	
	return false;
}

void CSnake::Debug()
{
	for (int i = 0; i < size; i++) {
		cell[i]->Debug();
	}
}
