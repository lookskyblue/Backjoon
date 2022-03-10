#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <deque>
#include <string>
#include <cstdlib>

using namespace std;

int map[300][300];
bool visit[300][300];
int tmp1;
int tmp2;

void Pass(int& from)
{
	tmp2 = from;
	from = tmp1;
	tmp1 = tmp2;
}

void Down(int& x1, int& y1, int x2, int y2)
{
	for (; x1 < x2 && visit[x1][y1] == false; x1++)
	{
		visit[x1][y1] = true;
		Pass(map[x1][y1]);
	}

	x1--;
}

void Left(int& x1, int& y1, int x2, int y2)
{
	for (y1++; y1 < y2 && visit[x1][y1] == false; y1++)
	{
		visit[x1][y1] = true;
		Pass(map[x1][y1]);
	}
	y1--;
}

void Up(int& x1, int& y1, int x2, int y2)
{
	for (x1--; x1 > -1 && visit[x1][y1] == false; x1--)
	{
		visit[x1][y1] = true;
		Pass(map[x1][y1]);
	}
	x1++;
}

void Right(int& x1, int& y1, int x2, int y2)
{
	for (y1--; y1 > -1 && visit[x1][y1] == false; y1--)
	{
		visit[x1][y1] = true;
		Pass(map[x1][y1]);
	}

	map[x1][y1] = tmp1;
}


void Solve(int x, int y, int r)
{
	for (int k = 0; k < r; k++)
	{
		memset(visit, false, sizeof(visit));

		for (int i = 0, j = 0; visit[i][j] == false; i++, j++)
		{
			int x1 = i;
			int y1 = j;

			Down(x1, y1, x, y); 
			Left(x1, y1, x, y);
			Up(x1, y1, x, y); 
			Right(x1, y1, x, y);
		}
	}
}

void Show(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n, m, r; // n 세로 m 가로
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	Solve(n, m, r);
	Show(n, m);

	return 0;
}