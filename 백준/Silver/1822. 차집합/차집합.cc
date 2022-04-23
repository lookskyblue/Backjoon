#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

set<int> as, bs, diffs;

void Solve()
{
	for (set<int>::iterator itr = as.begin(); itr != as.end(); itr++)
	{
		if (bs.find(*itr) == bs.end())
			diffs.insert(*itr);
	}

	cout << diffs.size() << '\n';

	for (set<int>::iterator itr = diffs.begin(); itr != diffs.end(); itr++)
		cout << *itr << ' ';
}

void Input()
{
	int A, B;
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		int x;
		cin >> x;

		as.insert(x);
	}

	for (int i = 0; i < B; i++)
	{
		int x;
		cin >> x;

		bs.insert(x);
	}

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	Input();

	return 0;
}