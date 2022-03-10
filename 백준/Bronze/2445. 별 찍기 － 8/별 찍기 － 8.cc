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

	int half = (n * 2 - 1) / 2 + 1;

	for (int i = 0; i < half; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << "*";

		for (int j = 0; j < (half - i - 1) * 2; j++)
			cout << " ";

		for (int j = 0; j < i + 1; j++)
			cout << "*";

		cout << endl;
	}

	int left = ((n * 2 - 1) - half);

	for (int i = 0; i < left; i++)
	{
		for (int j = 0; j < left-i; j++)
			cout << "*";

		for (int j = 0; j < (i + 1) * 2; j++)
			cout << " ";

		for (int j = 0; j < left-i; j++)
			cout << "*";

		cout << endl;
	}

	return 0;
}