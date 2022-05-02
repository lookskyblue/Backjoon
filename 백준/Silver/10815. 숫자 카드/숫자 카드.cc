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

set<int> my_card;

void Input()
{
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		my_card.insert(x);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;

		if (my_card.find(x) == my_card.end())
			cout << 0 << ' ';
		else
			cout << 1 << ' ';
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