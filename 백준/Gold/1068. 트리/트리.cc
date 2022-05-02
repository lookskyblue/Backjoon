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
int remove_idx;
int root_idx;

map<int, int> m;

void Remove(int idx)
{
	int removes_parent = m[idx];
	for (vector<int>::iterator i = nodes[removes_parent].begin(); i != nodes[removes_parent].end(); i++)
	{
		if (*i == idx)
		{
			nodes[removes_parent].erase(i);
			return;
		}
	}

	return;
	
	for (int i = 0; i < nodes[idx].size(); i++)
		Remove(nodes[idx][i]);

	nodes[idx].clear();
}

void DFS(int idx)
{
	//if (idx == remove_idx) return;

	if (nodes[idx].size() == 0)
	{
		//cout << "IDX: " << idx << '\n';
		ans++;
		return;
	}

	for (int i = 0; i < nodes[idx].size(); i++)
		DFS(nodes[idx][i]);
}

void Print(int idx)
{
	cout << "부모 노드: " << idx << '\n';

	for (int i = 0; i < nodes[idx].size(); i++)
	{
		cout << "자식 노드: " << nodes[idx][i] << '\n';
		Print(nodes[idx][i]);
	}

	cout << "끝" << '\n';
}

void Input()
{
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
		m.insert({i, x});
	}

	cin >> remove_idx;

	 //Remove(remove_idx);
	 //DFS(0);
	 //cout << ans;
	// Print(0);
	/*DFS(root_idx);
	int all_leaf = ans;

	ans = 0;
	DFS(remove_idx);
	int after_remove_leaf = ans;

	cout << "ALL LEAF: " << all_leaf << ", AFTER ALL LEAF: " << after_remove_leaf << '\n';
	cout << all_leaf - after_remove_leaf;

	for (int i = 0; i < N; i++)
		nodes[i].clear();*/

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