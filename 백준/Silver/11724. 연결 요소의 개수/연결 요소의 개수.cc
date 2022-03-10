#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

bool map[1001][1001];
bool visit[1001];

void Bfs(int start, int n)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (map[now][i] == true && visit[i] == false)
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
		map[y][x] = true;
	}


	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			Bfs(i, n);
			count++;
		}
	}

	cout << count;

	return 0;
}