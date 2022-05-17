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

char room[100][100];

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> room[i][j];
		}
	}

	int row_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int empty_cnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (room[i][j] == '.') empty_cnt++;

			else
			{
				if (empty_cnt >= 2) row_cnt++;

				empty_cnt = 0;
			}
		}

		if (empty_cnt >= 2) row_cnt++;
	}

	int colum_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int empty_cnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (room[j][i] == '.') empty_cnt++;

			else
			{
				if (empty_cnt >= 2) colum_cnt++;
				
				empty_cnt = 0;
			}
		}

		if (empty_cnt >= 2) colum_cnt++;
	}

	cout << row_cnt << ' ' << colum_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}