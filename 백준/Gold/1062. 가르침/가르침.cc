#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int N, K;
vector<string> v;
bool reader[26];
int word_count;
int max_word;

void CheckWord()
{
	for (int i = 0; i < v.size(); i++)
	{
		bool can_read = true;

		for (int j = 0; j < v[i].size(); j++)
		{
			if (reader[v[i][j] - 'a'] == false)
			{
				can_read = false;
				break;
			}
		}

		if (can_read == true)
			word_count++;
	}
}

void DFS(int idx, int cnt)
{
	if (cnt == K)
	{
		CheckWord();
		max_word = max(max_word, word_count);
		word_count = 0;

		return;
	}

	for (int i = idx; i < 26; i++)
	{
		if (reader[i] == true) continue;

		reader[i] = true;
		DFS(i+1, cnt + 1);
		reader[i] = false;
	}
}

void Solve()
{
	if (K < 5)
	{
		cout << 0;
		return;
	}

	reader['a' - 'a'] = true;
	reader['c' - 'a'] = true;
	reader['n' - 'a'] = true;
	reader['t' - 'a'] = true;
	reader['i' - 'a'] = true;

	K -= 5;

	DFS(0, 0);

	cout << max_word;
}

void Input()
{
	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		v.push_back(str);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}