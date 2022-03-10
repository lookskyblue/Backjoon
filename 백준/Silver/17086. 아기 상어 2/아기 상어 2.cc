#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

bool is_shark[50][50];
bool visit[50][50];
int dist[50][50];

int dx[8] = { -1, 0, 1, 1, 1, 0,  -1, - 1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

int queuing(int i, int j, int h, int w)
{
	memset(visit, false, sizeof(visit));
	memset(dist, 0, sizeof(dist));

	queue<pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = true;

	//cout << "i: " << i << " j: " << j << endl;

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		//cout << "pop x: " << x << " y: " << y << endl;

		if (is_shark[x][y] == true)
		{
			//cout << "sp - x: " << x << " y: " << y << " dist: " << dist[x][y] << endl;
			return dist[x][y];
		}

		for (int l = 0; l < 8; l++)
		{
			int nx = x + dy[l];
			int ny = y + dx[l];

			if (0 <= nx && nx < h && 0 <= ny && ny < w && visit[nx][ny] == false)
			{
				//cout << "nx: " << nx << " ny: " << ny << endl;
				visit[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

void Bfs(int h, int w)
{
	int max_safe_dist = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (is_shark[i][j] == false)
			{
				max_safe_dist = max(queuing(i, j, h, w), max_safe_dist);
				//queuing(0, 3, h, w);
				//return;
			}
		}
	}

	cout << max_safe_dist;
}

int main()
{
	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int val;
			cin >> val;
			is_shark[i][j] = val == 1 ? true : false;
		}
	}

	Bfs(h, w);

	return 0;
}