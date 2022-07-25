#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

void Solve()
{
	int N;
	vector<int> P;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		P.push_back(x);
	}

	sort(P.begin(), P.end());

	int waited_time = 0;
	int sum = 0;

	for (int i = 0; i < P.size(); i++)
	{
		waited_time += P[i];
		sum += waited_time;
	}

	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();

	return 0;
}