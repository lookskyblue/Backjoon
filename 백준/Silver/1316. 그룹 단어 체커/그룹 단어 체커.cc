#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int alpha[26];

int main()
{
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		bool is_continue = true;

		for (int j = 0; j < word.size(); j++)
		{
			++alpha[word[j] - 'a'];

			if (j >= 1 && word[j] != word[j - 1] && (alpha[word[j] - 'a'] >= 2))
			{
				is_continue = false;
				break;
			}
		}

		is_continue == true ? ans++ : ans;

		memset(alpha, 0, sizeof(alpha));
	}

	cout << ans;

	return 0;
}