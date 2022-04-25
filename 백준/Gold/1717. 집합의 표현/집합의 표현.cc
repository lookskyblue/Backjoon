#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>;
#include <map>;

using namespace std;

int parent[1000001];

int Find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
}

void Input()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0)
			Union(a, b);

		else
			cout << (Find(a) == Find(b) ? "YES" : "NO") << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}
