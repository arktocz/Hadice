// Had_2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CSnake.h"



HANDLE  hConsoleOut;                   /* Handle ke konzolovemu oknu */
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;   /* informace o konzolovem okne */

void Frame() {
	for (int i = 1; i < 100; i++) {
		PrintXY(i, 0, "=");
		PrintXY(i, 29, "=");
	}
	for (int i = 0; i < 29; i++) {
		PrintXY(1, i, "I");
		PrintXY(99, i, "I");
	}
}


void PrintXY(int x,int y,char *str) {
 COORD coord;
 DWORD written;

	coord.X=x;
	coord.Y=y;

	WriteConsoleOutputCharacter(hConsoleOut,str,(DWORD)strlen(str),coord,&written);

}

// *** smaze konzolovou obrazovku
void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy );
}


int _tmain(int argc, _TCHAR* argv[])
{
    /* Otevreme konzolove okno a ziskame informace o jejich parametrech.*/
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );

	ClearScreen();
	srand((unsigned)time(NULL));
	//CLod lod;
	Frame();
	int score = 0;
	CSnake snake;
	bool konec = false;
	char input = 'l';
	do {
		if (_kbhit()) {
			input = _getch();
		}
		switch (input) {
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
		if (snake.Move())
		{
			score++;
		}
		printf("\r");
		printf(" score: %d", score);
		konec = snake.BodyCheck();
		if (konec==false)
		{
			konec = snake.BorderCheck();
		}
	} while (input != 'q' && konec !=true);



	ClearScreen();
	printf("\a");
	printf("\t\t\t TVE SCORE JE: %d\n", score);
	printf("\n");
	printf("\t\t\tStiskni cokoliv pro ukonceni aplikace ...\n");
	while( !_kbhit() );


   return 0;
}
