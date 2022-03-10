#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
bool map[101][101];
bool visit[101];
int length[101];

void Bfs(int from, int to, int n)
{
	queue<int> q;
	q.push(from);
	visit[from] = true;

	while (q.empty() == false)
	{
		int now_person = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (map[now_person][i] == true && visit[i] == false)
			{
				visit[i] = true;
				q.push(i);
				length[i] = length[now_person] + 1;
			}
		}
	}

	int result = length[to] == 0 ? -1 : length[to];

	cout << result;
}

int main()
{
	int n, from, to, r;
	cin >> n >> from >> to >> r;

	for (int i = 0; i < r; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	Bfs(from, to, n);

	return 0;
}