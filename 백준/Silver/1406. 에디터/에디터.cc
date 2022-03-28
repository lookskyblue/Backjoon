#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <list>

using namespace std;

int cursor;

void Solve()
{
	string str;
	int M;

	cin >> str >> M;

	list<char> ls(str.begin(), str.end());
	list<char>::iterator now = ls.end();

	for (int i = 0; i < M; i++)
	{
		char order;
		cin >> order;

		if (order == 'L' && now != ls.begin())
			now--;

		else if (order == 'D' && now != ls.end())
			now++;

		else if (order == 'B' && now != ls.begin())
			now = ls.erase(--now);

		else if(order == 'P')
		{
			char alpha;
			cin >> alpha;

			ls.insert(now, alpha);
		}
	}

	for (list<char>::iterator itr = ls.begin(); itr != ls.end(); itr++)
		cout << *itr;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}