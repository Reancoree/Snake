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
int tailX[100], tailY[100];
int lTail;

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

			else
			{
				bool print = false;
				for (int k = 0; k < lTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << 'o';
						print = true;
					}
				}

				if (!print)
					cout << ' ';
			}

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
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < lTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

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

	for (int i = 0; i < lTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		lTail++;
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