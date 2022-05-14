#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

void Solve()
{
	string A, B;
	cin >> A >> B;

	int m = 50;

	for (int j = 0; j < B.size() - A.size() + 1; j++)
	{
		int cnt = 0;

		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] != B[i+j])
				cnt++;
		}

		m = min(cnt, m);
	}

	cout << m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}