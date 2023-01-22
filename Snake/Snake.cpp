#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void FixSnakeSpeed()
{
	if (dir == LEFT || dir == RIGHT)
	{
		Sleep(5);
	}

	Sleep(100);

	if (dir == UP || dir == DOWN)
	{
		Sleep(60);
	}
}
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	
	for (int i = 0; i < width + 2; i++)
		cout << (char)254;
	cout << "      Score: " << score;
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << (char)254;

			if (i == y && j == x)
				cout << 'O';
			else if (i == fruitY && j == fruitX)
				cout << '*';

			else cout << ' ';

			if (j == width - 1)
				cout << (char)254;
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << (char)254;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'esc':
			gameOver = false;
			break;
		}
	}
}
void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x < 0 || x > width || y < 0 || y > height)
		gameOver = true;


	if (x == fruitX && y == fruitY)
	{
		score += 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
		
}

int main()
{
	
	Setup();
	while (!gameOver)
	{
		Draw();
		FixSnakeSpeed();
		Input();
		Logic();
	}

	return 0;
}