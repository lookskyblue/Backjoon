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

void Solve()
{
	int N;
	cin >> N;
	vector<int> v;

	while (N != 0)
	{
		v.push_back(N % 10);
		N /= 10;
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}