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

char map[50][50];
int max_candy;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Swap(char& a, char& b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void SearchMax(int x1, int y1, int x2, int y2, int n)
{
	int arr_x[2] = { x1, x2 };
	int arr_y[2] = { y1, y2 };

	for (int idx = 0; idx < 2; idx++)
	{
		for (int count = 1, i = 1; i < n; i++)
		{
			if (map[arr_x[idx]][i - 1] == map[arr_x[idx]][i])
			{
				max_candy = max(max_candy, ++count);
			}

			else
				count = 1;
		}

		for (int count = 1, i = 1; i < n; i++)
		{
			if (map[i - 1][arr_y[idx]] == map[i][arr_y[idx]])
			{
				max_candy = max(max_candy, ++count);
			}

			else
				count = 1;
		}
	}
}


void Solve(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dy[k];
				int ny = j + dx[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < n)
				{
					Swap(map[i][j], map[nx][ny]);
					SearchMax(i, j, nx, ny, n);
					Swap(map[i][j], map[nx][ny]);
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		
		for (int j = 0; j < n; j++)
		{
			map[i][j] = line[j];
		}
	}

	Solve(n);
	cout << max_candy;
	return 0;
}