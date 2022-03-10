#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, N;
char map[200][200];
bool will_bomb[200][200];

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1 };

void Input()
{
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
}

void Print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void DropFullBomb()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.') map[i][j] = 'O';
			else will_bomb[i][j] = true;
		}
	}
}

void BombSome()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'O' && will_bomb[i][j] == true)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dy[k];
					int ny = j + dx[k];

					if (0 <= nx && nx < R && 0 <= ny && ny < C && map[nx][ny] == 'O' && will_bomb[nx][ny] == false)
					{
						map[nx][ny] = '.';
					}
				}

				will_bomb[i][j] = false;
				map[i][j] = '.';
			}
		}
	}
}

void Solve()
{
	int time = 1;

	while (N != 1)
	{
		DropFullBomb();

		if (++time == N) break;

		BombSome();

		if (++time == N) break;
	}
}

int main()
{
	Input();
	Solve();
	Print();

	return 0;
}