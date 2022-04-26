#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>;
#include <map>;

using namespace std;

vector<int> v[100001];
bool visited[100001];
int parent[100001];
int N;

void Dfs(int idx)
{
	visited[idx] = true;

	for (int i = 0; i < v[idx].size(); i++)
	{
		int element = v[idx][i];
		
		if (visited[element] == true) continue;
		
		parent[element] = idx;
		Dfs(element);
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void Solve()
{
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Dfs(1);
	Solve();

	return 0;
}
