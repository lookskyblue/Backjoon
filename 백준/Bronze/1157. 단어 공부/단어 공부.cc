#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int alpha[26];

void Solve()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z') // 대문자일 경우
			alpha[(str[i] + 32) - 'a']++;
		else
			alpha[str[i] - 'a']++;
	}

	int max_alpha = 0;
	int max_alpha_cnt = 0;
	int max_alpha_real = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max_alpha < alpha[i])
		{
			max_alpha_cnt = 1;
			max_alpha = alpha[i];
			max_alpha_real = i;
		}

		else if (max_alpha == alpha[i]) max_alpha_cnt++;
	}

	if (max_alpha_cnt >= 2) cout << "?";
	else cout << (char)('A' + max_alpha_real);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}