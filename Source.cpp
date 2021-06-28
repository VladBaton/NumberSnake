#include <iostream>
#include <iomanip>
using namespace std;


class Position
{

protected :
	int N;
	int M;
	int rightBorder;
	int downBorder;
	int leftBorder;
	int upBorder;
	int x;
	int y;
	int stepsCounter;
public : 
	Position(int N, int M) : rightBorder(N), N(N), downBorder(M), M(M), leftBorder(0), upBorder(0), stepsCounter(0), x(0), y(0) {}
};

class Game : public Position
{
private :
	int** gameMap;
public:
	Game(int N, int M) : Position(N, M)
	{
		gameMap = new int* [M];
		for (int i = 0; i < M; i++)
			gameMap[i] = new int[N];
		gameMap[x][y] = stepsCounter;
	}
	void stepRight()
	{
		x++;
		stepsCounter++;
		gameMap[y][x] = stepsCounter;
	}
	void stepLeft()
	{
		x--;
		stepsCounter++;
		gameMap[y][x] = stepsCounter;
	}
	void stepUp()
	{
		y--;
		stepsCounter++;
		gameMap[y][x] = stepsCounter;
	}
	void stepDown()
	{
		y++;
		stepsCounter++;
		gameMap[y][x] = stepsCounter;
	}
	void playTheGame(void)
	{
		while (stepsCounter < N * M - 1)
		{
			while (x < rightBorder - 1 && stepsCounter < N * M - 1)
				stepRight();
			rightBorder--;
			while (y < downBorder -1 && stepsCounter < N * M - 1)
				stepDown();
			downBorder--;
			while (x > leftBorder && stepsCounter < N * M - 1)
				stepLeft();
			leftBorder++;
			while (y > upBorder + 1 && stepsCounter < N * M - 1)
				stepUp();
			upBorder++;
		}
	}
	void showMap() const
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout.width(3);
				cout << gameMap[i][j];
			}
			cout << endl;
		}
	}
};


int main()
{

	int N, M;
	setlocale(LC_ALL, "Russian");
	cout << "Программа принимает 2 натуральных числа N и M и выводит на экран\n" <<
		"массив в виде змейки.\n Введите M и N : ";
	cin >> M >> N;
	
	Game myGame(N, M);
	myGame.playTheGame();
	myGame.showMap();

	return 0;
}