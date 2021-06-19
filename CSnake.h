#pragma once
#include"CPoint.h"
#define MAXSIZE 100

	class CSnake {
	private:
		CPoint* cell[MAXSIZE]; // array of points to represent snake
		int size; // current size of snake
		char dir; // current direction of snake
		CPoint fruit;
	public:
		CSnake();
		void AddCell(int x, int y);
		void TurnUp();
		void TurnDown();
		void TurnLeft();
		void TurnRight();
		bool Move();
		bool BodyCheck();
		bool BorderCheck();
		void Debug();
	};

