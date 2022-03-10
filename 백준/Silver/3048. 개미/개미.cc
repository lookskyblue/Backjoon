#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

void Solve(int n1, int n2, string s1, string s2, string s3, int t)
{
	for (int c = 0; c < t; c++)
	{
		for (int i = 0; i < n1 + n2 - 1; i++)
		{
			if (s1.find(s3[i]) != string::npos && s2.find(s3[i + 1]) != string::npos)
			{
				swap(s3[i], s3[i + 1]);
				i++;
			}
		}
	}

	cout << s3;
}

int main()
{
	int n1, n2, t;
	string s1, s2, s3;

	cin >> n1 >> n2;
	cin >> s1 >> s2;
	cin >> t;

	reverse(s1.begin(), s1.end());
	s3 = s1 + s2;

	Solve(n1, n2, s1, s2, s3, t);

	return 0;
}