#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;
int good_word_count;

void IsGoodWord(string word)
{
	stack<char> letter_s;

	for (int i = 0; i < word.size(); i++)
	{
		char letter = word[i];

		if (letter_s.empty() == true) letter_s.push(letter);

		else
		{
			if (letter_s.top() == letter) letter_s.pop();
			else letter_s.push(letter);
		}
	}

	if (letter_s.empty() == true) good_word_count++;
}

void Input()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;

		IsGoodWord(word);

	}

	cout << good_word_count;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}