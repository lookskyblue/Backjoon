#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int v[300][300];
int length[300][300];

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1};

int Bfs(int n, int npy, int npx, int dpy, int dpx)
{
	queue<pair<int, int>> q;

	q.push(make_pair(npx, npy));
	v[npx][npy] = 1;

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == dpx && y == dpy)
			return length[dpx][dpy];

		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (0 <= xx && xx < n && 0 <= yy && yy < n && v[xx][yy] == 0)
			{
				v[xx][yy] = 1;
				length[xx][yy] = length[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) // 테스트 케이스 만큼 반복
	{
		int map_size, now_pos_x, now_pos_y, des_pos_x, des_pos_y;

		cin >> map_size >> now_pos_x >> now_pos_y >> des_pos_x >> des_pos_y;
		cout << Bfs(map_size, now_pos_x, now_pos_y, des_pos_x, des_pos_y) << endl;

		memset(v, 0, sizeof(v));
		memset(length, 0, sizeof(length));
	}

	return 0;
} 