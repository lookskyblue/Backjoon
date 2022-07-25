#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int N, M;
vector<int> A;

void Solve()
{
	int answer = 0;
	int s = 0, e = 0;
	int sum = 0;

	while (true)
	{
		if (sum >= M) sum -= A[s++];
		else if (e == N) break;
		else sum += A[e++];
		
		if (sum == M) answer++;
	}

	cout << answer;
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
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