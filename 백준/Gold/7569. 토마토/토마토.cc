#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int map[100][100][100];
int length[100][100][100];

int dv[6] = { -1, 1, 0, 0, 0, 0 };
int dh[6] = { 0, 0, -1, 1, 0, 0 };
int dw[6] = { 0, 0, 0, 0, -1, 1 };

int main()
{
	int v, h, w, max_day = 0;
	cin >> w >> h >> v;
	queue < pair<pair<int, int>, int>> q;

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				cin >> map[i][j][k];

				if (map[i][j][k] == 1)
					q.push({ { i, j }, k });
			}
		}
	}

	while (q.empty() == false)
	{
		int i = q.front().first.first;
		int j = q.front().first.second;
		int k = q.front().second;

		q.pop();

		for (int l = 0; l < 6; l++)
		{
			int nv = dv[l] + i;
			int nh = dh[l] + j;
			int nw = dw[l] + k;

			if (0 <= nv && nv < v && 0 <= nh && nh < h && 0 <= nw && nw < w && map[nv][nh][nw] == 0)
			{
				map[nv][nh][nw] = map[i][j][k] + 1;
				q.push({ {nv, nh}, nw });
			}
		}
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				if (map[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}

				max_day = max(max_day, map[i][j][k]);
			}
		}
	}

	cout << max_day - 1;
	return 0;
} 