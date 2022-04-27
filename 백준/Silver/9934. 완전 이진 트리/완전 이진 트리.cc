#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>

using namespace std;

int visit_node[1024];
vector<int> bfs_node[10];

void Bfs(int depth, int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;

	bfs_node[depth].push_back(visit_node[mid]);
	Bfs(depth + 1, start, mid);
	Bfs(depth + 1, mid + 1, end);
}

void Input()
{
	int k, depth;
	cin >> k;
	depth = k;
	
	k = (1 << k) - 1;

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;

		visit_node[i] = x;
	}

	Bfs(0, 0, k);

	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < bfs_node[i].size(); j++)
			cout << bfs_node[i][j] << " ";

		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}