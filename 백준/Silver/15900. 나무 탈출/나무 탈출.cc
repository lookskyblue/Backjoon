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

vector<int> nodes[500001];
bool visit[500001] = { false, };
int N;
int ans;

void DFS(int start, int height)
{
	if (nodes[start].size() == 1 && start != 1)
	{
		ans += height;
		return;
	}

	for (int i = 0; i < nodes[start].size(); i++)
	{
		if (visit[nodes[start][i]] == false)
		{
			visit[nodes[start][i]] = true;
			DFS(nodes[start][i], height + 1);
		}
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	visit[1] = true;
	DFS(1, 0);

	cout << ((ans % 2 == 1) ? "Yes" : "No");

	return 0;
}