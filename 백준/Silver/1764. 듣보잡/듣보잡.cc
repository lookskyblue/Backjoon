#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N, M;
vector<string> nv, common;

void Solve()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		nv.push_back(tmp);
	}

	sort(nv.begin(), nv.end());

	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;

		if (binary_search(nv.begin(), nv.end(), tmp) == true)
			common.push_back(tmp);
	}

	sort(common.begin(), common.end());

	cout << common.size() << "\n";

	for (int i = 0; i < common.size(); i++)
		cout << common[i] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}