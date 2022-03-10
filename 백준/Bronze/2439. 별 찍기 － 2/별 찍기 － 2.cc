#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = n - i; j > 0; j--)
			cout << " ";

		for (int j = 0; j < i; j++)
			cout << "*";

		cout << endl;
	}

	return 0;
}