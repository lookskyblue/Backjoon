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
	string N;
	cin >> N;

	sort(N.begin(), N.end(), greater<char>());
	int num_sum = 0;

	for (int i = 0; i < N.length(); i++)
	{
		num_sum += int(N[i] - '0');
		//cout << "Ni: " << N[i] << ", : " << N[i] - '0' << ", num_sum: "<<num_sum << '\n';
	}

	//if (num_sum % 3 == 0)
	//	cout << "TRUE" << num_sum<< '\n';

	if (N[N.length() - 1] == '0' && num_sum % 3 == 0)
		cout << N;
	else
		cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}