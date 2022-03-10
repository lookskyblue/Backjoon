#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int medal[1001][4];

void Solv(int countries, int k, int ki)
{
	int rank = 1;

	for (int i = 0; i < countries; i++)
	{
		if (medal[ki][1] < medal[i][1]) rank++;

		else if (medal[ki][1] == medal[i][1])
		{
			if (medal[ki][2] < medal[i][2]) rank++;

			else if (medal[ki][2] == medal[i][2])
				if (medal[ki][3] < medal[i][3]) rank++;
		}
	}

	cout << rank;
}

int main()
{
	int n, k, ki;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> medal[i][0];
		
		if (medal[i][0] == k)
			ki = i;

		for (int j = 1; j < 4; j++)
		{
			cin >> medal[i][j];
		}
	}

	Solv(n, k, ki);

	return 0;
}