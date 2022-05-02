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

int N;
vector<int> nodes[50];
int ans;

map<int, int> node_parent_mapping;

void Remove(int idx)
{
	int parent = node_parent_mapping[idx];

	for (vector<int>::iterator i = nodes[parent].begin(); i != nodes[parent].end(); i++)
	{
		if (*i == idx)
		{
			nodes[parent].erase(i);
			return;
		}
	}
}

void DFS(int idx)
{
	if (nodes[idx].size() == 0)
	{
		ans++;
		return;
	}

	for (int i = 0; i < nodes[idx].size(); i++)
		DFS(nodes[idx][i]);
}

void Input()
{
	int root_idx, remove_idx;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == -1)
		{
			root_idx = i;
			continue;
		}

		nodes[x].push_back(i);
		node_parent_mapping.insert({i, x});
	}

	cin >> remove_idx;

	Remove(remove_idx);
	DFS(root_idx);

	if (remove_idx == root_idx)
		cout << 0;
	else 
		cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}