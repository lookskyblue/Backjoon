#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

void Solve()
{
	int ANS = 0, N, M;
	string S;

	cin >> N >> M >> S;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == 'I')
		{
			int cnt = 0;

			while (i + 2 < S.length() && S[i + 1] == 'O' && S[i + 2] == 'I')
			{
				cnt++;

				if (cnt == N)
				{
					ANS++;
					cnt--;
				}

				i += 2;
			}
		}
	}

	cout << ANS;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}