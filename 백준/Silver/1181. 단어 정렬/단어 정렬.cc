#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

set<string> words;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		set<string>::iterator itr = words.find(str);

		if (itr == words.end())
		{
			words.insert(str);
			pq.push({ str.length(), str });
		}
	}

	while (pq.empty() == false)
	{
		cout << pq.top().second << '\n';
		pq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}