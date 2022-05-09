#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#define INF 987654321
#define MAX 101

using namespace std;

int N, M;
int maze[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void Solve()
{
	queue<pair<int, int>> pq;
	pq.push({ 1, 1 });
	dp[1][1] = 0;

	while (pq.empty() == false)
	{
		int x = pq.front().first;
		int y = pq.front().second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 < nx && nx <= M && 0 < ny && ny <= N)
			{
				if (dp[nx][ny] > dp[x][y] + maze[nx][ny])
				{
					dp[nx][ny] = dp[x][y] + maze[nx][ny];
					pq.push({ nx, ny });
				}
			}
		}
	}

	cout << dp[M][N];
}

void Input()
{
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		string x;
		cin >> x;

		for (int j = 0; j < x.size(); j++)
		{
			maze[i][j+1] = x[j] - '0';
			dp[i][j+1] = INF;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}