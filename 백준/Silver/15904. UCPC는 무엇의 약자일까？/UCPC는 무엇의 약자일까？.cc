#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

void Solve()
{
	stringstream ss;
	string ucpc = "UCPC";
	string word;
	string str;

	getline(cin, str);
	ss.str(str);

	int ucpcIdx = 0;

	while (getline(ss, word, ' '))
	{
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == ucpc[ucpcIdx])
			{
				ucpcIdx++;

				if (ucpcIdx == 4) break;
			}
		}
	}

	cout << (ucpcIdx == 4 ? "I love UCPC" : "I hate UCPC") << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}