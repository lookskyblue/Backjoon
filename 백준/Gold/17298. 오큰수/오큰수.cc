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
stack<int> s;
int ans[1000000];
int N;

void Solve()
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		while (s.empty() == false && s.top() <= v[i])
		{
			s.pop();
		}

		if (s.empty() == true)
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(v[i]);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
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