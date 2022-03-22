#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

void Solve()
{
	vector<pair<int, int>> pair_pos;
	vector<int> laser_pos;
	stack<int> s;

	string bracket;
	cin >> bracket;

	for (int i = 0; i < bracket.size(); i++)
	{
		if (bracket[i] == '(')
		{
			s.push(i);
		}

		else
		{
			int pos = s.top();
			s.pop();

			if (i - pos == 1) laser_pos.push_back(pos);
			else pair_pos.push_back({ pos, i });
		}
	}

	int sum = 0;

	for (int i = 0; i < pair_pos.size(); i++)
	{
		int divided_one_stick = 0;

		for (int j = 0; j < laser_pos.size(); j++)
		{
			if ((pair_pos[i].first < laser_pos[j] && laser_pos[j] < pair_pos[i].second))
				divided_one_stick++;

			else if (pair_pos[i].second < laser_pos[j]) break;
		}

		sum += (divided_one_stick + 1);
	}

	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}