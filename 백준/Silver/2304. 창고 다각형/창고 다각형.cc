#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first) return true;
	else return false;
}

void Solve()
{
	int total_sum = 0;
	int left_idx = v[0].first, left_max = v[0].second;

	int left_sum = 0, right_sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (left_max <= v[i].second)
		{
			total_sum += left_max * (v[i].first - left_idx);
			left_sum += left_max * (v[i].first - left_idx);

			left_idx = v[i].first;
			left_max = v[i].second;
		}
	}

	int right_idx = v[v.size() - 1].first, right_max = v[v.size() - 1].second;

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (right_max < v[i].second)
		{
			total_sum += right_max * (right_idx - v[i].first);
			right_sum += right_max * (right_idx - v[i].first);

			right_idx = v[i].first;
			right_max = v[i].second;
		}
	}

	//cout << "LEFT SUM: " << left_sum << '\n';
	//cout << "RIGHT SUM: " << right_sum << '\n';
	//cout << "LEFT MAX: " << left_max << '\n';

	cout << total_sum + left_max;
}

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;

		v.push_back({L, H});
	}

	sort(v.begin(), v.end(), compare);

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}
