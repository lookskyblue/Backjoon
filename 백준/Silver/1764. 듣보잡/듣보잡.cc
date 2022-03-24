#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N, M;
set<string> s;
vector<string> common;

void Solve()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		s.insert(tmp);
	}

	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp; 

		if (s.find(tmp) != s.end())
		{
			common.push_back(tmp);
		}
	}

	sort(common.begin(), common.end());

	cout << common.size() << "\n";

	for (int i = 0; i < common.size(); i++)
	{
		cout << common[i] << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}