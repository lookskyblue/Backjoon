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

vector<int> v;
int max_value = 2000000001;
int N;
int first_s, second_s;

void BS(int value, int idx)
{
	int start = idx + 1;
	int end = v.size();

	while (start < end)
	{
		int mid = (start + end) / 2;

		if (abs(value) <= v[mid])
			end = mid;
		else
			start = mid + 1;

		if (abs(value + v[mid]) < abs(max_value))
		{
			max_value = value + v[mid];
			first_s = value;
			second_s = v[mid];
		}
	}
}

void Solve()
{
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
		BS(v[i], i);

	cout << first_s << ' ' << second_s;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}