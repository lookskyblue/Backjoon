#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

void Solve()
{
	int x;

	cin >> x;

	int result = (x * (1 + x)) / 2;

	cout << result;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}