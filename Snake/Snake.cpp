#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 30;
int x, y, fruitX, fruitY, score;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

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

	for (int i = 0; i < width + 1; i++)
		cout << (char)254;
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

	for (int i = 0; i < width + 1; i++)
		cout << (char)254;
}
void Input()
{

}
void Logic()
{

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}

	return 0;
}