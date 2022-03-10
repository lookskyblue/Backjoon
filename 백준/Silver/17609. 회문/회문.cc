#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string strs[30];

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> strs[i];
}

bool IsNone(string str, int remove_idx)
{
	str.erase(remove_idx, 1);

	for (int i = 0; i <= str.size() / 2 - 1; i++)
		if (str[i] != str[str.size() - i - 1])
			return true;

	return false;
}

void Solve()
{
	for (int i = 0; i < n; i++)
	{
		int palindrome_state = 0;

		for (int j = 0; j <= strs[i].size() / 2 - 1; j++)
		{
			if (strs[i][j] != strs[i][strs[i].size() - j - 1])
			{
				palindrome_state++;

				if (IsNone(strs[i], j) == true && IsNone(strs[i], strs[i].size() - j - 1) == true)
					palindrome_state++;

				break;
			}
		}

		cout << palindrome_state << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	Input();
	Solve();

	return 0;
}