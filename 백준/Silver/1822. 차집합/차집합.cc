#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>

using namespace std;

set<int> s;

void Input()
{
	int A, B;
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		int x;
		cin >> x;

		s.insert(x);
	}

	for (int i = 0; i < B; i++)
	{
		int x;
		cin >> x;

		if (s.find(x) != s.end())
			s.erase(x);
	}

	cout << s.size() << '\n';

	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++)
		cout << *itr << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}