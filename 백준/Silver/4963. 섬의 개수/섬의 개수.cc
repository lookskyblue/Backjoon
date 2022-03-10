#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int map[50][50];
bool v[50][50];
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

void Bfs(int i, int j, int h, int w)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	v[i][j] = 1;

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int j = 0; j < 8; j++)
		{
			int next_x = x + dx[j];
			int next_y = y + dy[j];

			if (0 <= next_x && next_x < h && 0 <= next_y && next_y < w && v[next_x][next_y] == false && map[next_x][next_y] == 1)
			{
				v[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}

int main()
{
	while (1)
	{
		int w, h;
		cin >> w >> h;

		if (w + h == 0) return 0;

		// 맵 입력 받기
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		// 해당 맵의 섬 개수 출력
		int land_count = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && v[i][j] == false)
				{
					Bfs(i, j, h, w);
					land_count++;
				}
			}
		}

		cout << land_count << endl;

		memset(map, 0, sizeof(map));
		memset(v, false, sizeof(v));
	}


	return 0;
} 