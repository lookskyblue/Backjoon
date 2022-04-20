#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

set<string> str_set;

void Input()
{
	int N, M, answer = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		str_set.insert(str);
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		if (str_set.find(str) != str_set.end())
			answer++;
	}

	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}