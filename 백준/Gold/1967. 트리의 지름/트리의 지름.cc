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

using namespace std;

vector<pair<int, int>> v[10001];
bool visit[10001];
int end_point;
int result;

void DFS(int start, int len)
{
	if (visit[start] == true) return;

	visit[start] = true;

	if (result < len)
	{
		result = len;
		end_point = start;
	}

	for (int i = 0; i < v[start].size(); i++)
		DFS(v[start][i].first, len + v[start][i].second);
}

void Solve()
{
	DFS(1, 0);
	memset(visit, false, sizeof(visit));
	result = 0;
	DFS(end_point, 0);

	cout << result;
}

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int par, ch, wei;
		cin >> par >> ch >> wei;

		v[par].push_back({ ch, wei });
		v[ch].push_back({ par, wei });
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