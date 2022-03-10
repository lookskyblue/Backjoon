#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int check[100][100];
bool map[100][100];
bool v[100][100];

bool IsValid(int i, int j, int n, int m)
{
	if (i < 0 || i == n || j < 0 || j == m) return false;
	if (v[i][j] == true || map[i][j] == false) return false;

	v[i][j] = true;

	return true;
}

void BFS(int n, int m)
{
	queue<pair<int, int>> q2;
	q2.push(make_pair(0, 0));

	v[n][m] = true;

	while (q2.empty() == false)
	{
		int x = q2.front().first;
		int y = q2.front().second;

		q2.pop();

		if (y == m - 1 && x == n - 1)
			break;

		else
		{
			if (IsValid(x + 1, y, n, m)) { q2.push(make_pair(x + 1, y)); check[x + 1][y] = check[x][y] + 1; }
			if (IsValid(x - 1, y, n, m)) { q2.push(make_pair(x - 1, y)); check[x - 1][y] = check[x][y] + 1; }
			if (IsValid(x, y + 1, n, m)) { q2.push(make_pair(x, y + 1)); check[x][y + 1] = check[x][y] + 1; }
			if (IsValid(x, y - 1, n, m)) { q2.push(make_pair(x, y - 1)); check[x][y - 1] = check[x][y] + 1; }
		}
	}

	cout << check[n - 1][m - 1] + 1;
}

int main()
{
	int n = 0, m = 0; // n세로 m 가로
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < m; j++)
		{
			if (line[j] == '1')
				map[i][j] = true;
		}
	}

	BFS(n, m);

	return 0;
} 