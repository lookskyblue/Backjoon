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

using namespace std;

void Solve()
{
	vector<string> v;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) v.push_back(str.substr(i));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}