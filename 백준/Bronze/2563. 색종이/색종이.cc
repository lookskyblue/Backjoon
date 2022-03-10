#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int map[101][101];

void PutPaper(int x, int y)
{
	int x1 = x;
	int x2 = x1 + 10;
	int y1 = y;
	int y2 = y1 + 10;

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			map[i][j] = 1;
		}
	}
}

void GetArea()
{
	int black_count = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1)
				black_count++;
		}
	}

	cout << black_count;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		PutPaper(x, y);
	}

	GetArea();

	return 0;
}