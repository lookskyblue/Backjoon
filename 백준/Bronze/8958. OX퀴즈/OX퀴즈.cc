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
#define INF 987654321
#define MAX 100001

using namespace std;

int T;

void Solve()
{
	while (T--)
	{
		string problem;
		cin >> problem;

		int total_score = 0;
		int score = 0;

		for (int i = 0; i < problem.length(); i++)
		{
			if (problem[i] == 'O') total_score += ++score;
			else score = 0;
		}

		cout << total_score << '\n';
	}
}

void Input()
{
	cin >> T;
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