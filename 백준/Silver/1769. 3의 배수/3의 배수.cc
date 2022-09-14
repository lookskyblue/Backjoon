#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void Solve()
{
	int changeCnt = 0;
	string Y;
	cin >> Y;

	while (Y.size() >= 2)
	{
		int sum = 0;

		for(int i = 0; i < Y.size(); i++)
		{
			sum += Y[i] - '0';
		}

		Y = to_string(sum);

		if (sum != 0)
			changeCnt++;
	}

	cout << changeCnt << '\n';
	cout << (((Y[0] - '0') % 3 == 0) ? "YES" : "NO") << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}