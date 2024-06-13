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

	int n = 1; // 분자
	int d = 1; // 분모

	int loopCount = 1;
	bool leftDir = true;

	while (loopCount != x)
	{
		if (leftDir)
		{
			d++;

			if (++loopCount == x)
			{
				break;
			}
		}
		else
		{
			n++;

			if (++loopCount == x)
			{
				break;
			}
		}

		int start = leftDir == true ? d : n;
		int end = 1;
		bool isFind = false;

		for (start; start != end; start--)
		{
			if (leftDir)
			{
				d--;
				n++;
			}
			else
			{
				d++;
				n--;
			}

			if (++loopCount == x)
			{
				isFind = true;
				break;
			}
		}

		if (isFind)
		{
			break;
		}

		leftDir = !leftDir;
	}

	cout << n << '/' << d;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}