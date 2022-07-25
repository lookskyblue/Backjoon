#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

void Solve()
{
	int N;
	cin >> N;

	vector<int> A, B;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		B.push_back(x);
	}

	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	sort(A.begin(), A.end());

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += A[i] * B[i];
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