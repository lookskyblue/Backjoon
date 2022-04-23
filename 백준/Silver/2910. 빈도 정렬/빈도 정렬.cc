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

map<int, pair<int, int>> frequency;

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
	if (a.second.first < b.second.first) return false;
	else if (a.second.first == b.second.first && a.second.second > b.second.second) return false;
	return true;
}

void Solve()
{
	vector<pair<int, pair<int, int>>> v;

	for (auto it = frequency.begin(); it != frequency.end(); it++)
		v.push_back(make_pair(it->first, it->second));

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		int loop_count = v[i].second.first;

		for (int j = 0; j < loop_count; j++)
			cout << v[i].first << ' ';
	}
}

void Input()
{
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		map<int, pair<int, int>>::iterator itr = frequency.find(x);

		if (itr == frequency.end()) frequency.insert({ x, {1, i} });
		else itr->second.first++;
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