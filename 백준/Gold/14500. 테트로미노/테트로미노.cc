#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int N, M;
int tetro[5];
int map[500][500];
bool visit[500][500];
int ans;
//stack<pair<int, int>> s;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void Dfs(int i, int j, int cnt)
{
	if (i < 0 || j < 0 || i == N || j == M) return;
	if (visit[i][j] == true) return;
	
	tetro[cnt] = map[i][j];

	if (cnt == 3)
	{
		int tmp = 0;
		for (int i = 0; i <= cnt; i++)
			tmp += tetro[i];

		ans = max(ans, tmp);
	}

	else
	{
		visit[i][j] = true;

		for (int k = 0; k < 4; k++)
		{
			int nx = i + dx[k];
			int ny = j + dy[k];

			Dfs(nx, ny, cnt + 1);
		}

		visit[i][j] = false;
	}
}

void SpecialBlock(int i, int j)
{
	vector<int> near_value;

	for (int k = 0; k < 4; k++)
	{
		int nx = i + dx[k];
		int ny = j + dy[k];

		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			near_value.push_back(map[nx][ny]);
		}
	}

	if (near_value.size() >= 3)
	{
		sort(near_value.begin(), near_value.end());

		int tmp = 0;
		int size = near_value.size();

		for (int m = size - 1; m >= size - 3; m--)
		{
			tmp += near_value[m];
		}

		ans = max(ans, tmp + map[i][j]);
	}
}

void Solve()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			Dfs(i, j, 0);
			SpecialBlock(i, j);
		}

	cout << ans;
}

int main()
{
	Input();
	Solve();
	return 0;
}