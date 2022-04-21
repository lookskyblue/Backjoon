#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

set<int> am, bm;

void Solve()
{
	set<int> tmp_am(am);

	for (set<int>::iterator itr = bm.begin(); itr != bm.end(); itr++) // A-B
	{
		if (tmp_am.find(*itr) != tmp_am.end())
		{
			tmp_am.erase(*itr);
		}
	}

	for (set<int>::iterator itr = am.begin(); itr != am.end(); itr++) // B-A
	{
		if (bm.find(*itr) != bm.end())
		{
			bm.erase(*itr);
		}
	}

	cout << tmp_am.size() + bm.size();
}

void Input()
{
	int A, B;
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		int x;
		cin >> x;

		am.insert(x);
	}

	for (int i = 0; i < B; i++)
	{
		int x;
		cin >> x;

		bm.insert(x);
	}

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}