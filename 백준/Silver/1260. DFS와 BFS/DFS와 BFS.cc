#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[1001][1001] = { 0 };

int visited[1001] = { 0 };


int n, m, k;

void dfs(int num)
{
	visited[num] = 1;
	cout << num << " ";
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0 && map[num][i] == 1)
		{
			dfs(i);
		}
	}
	
}

void bfs(int num, int n)
{
	queue<int> q1;
	q1.push(num);
	visited[num] = 1;
	cout << num << " ";
	while (!q1.empty())
	{
		int x = q1.front();
		q1.pop();

		for (int i = 1; i <= n; i++)
		{
			if (map[x][i] == 1 && visited[i] == 0)
			{
				q1.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}
	cout << endl;
	
}

int main() {
	

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	dfs(k);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	bfs(k, n);
	return 0;
}