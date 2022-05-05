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

void BS()
{
	int start = 0;
	int end = v.size() - 1;

	while (start != end)
	{
		int sum = (v[start] + v[end]);

		if (abs(sum) < abs(max_value))
		{
			max_value = sum;
			first_s = v[start];
			second_s = v[end];

			if (sum == 0)
				break;
		}

		if (sum < 0) start++;
		else if (sum > 0) end--;
	}
}

void Solve()
{
	sort(v.begin(), v.end());

	BS();

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