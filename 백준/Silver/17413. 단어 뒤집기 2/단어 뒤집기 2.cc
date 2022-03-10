#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <deque>
#include <string>

using namespace std;

string line;

void Reverse(int start, int last)
{
	string tmp = "";

	for (int i = last; i >= start; i--)
		tmp += line[i];

	for (int i = 0; i < tmp.size(); i++)
		line[start + i] = tmp[i];
}

void Solve()
{
	bool start_tag = false;
	bool start_str = false;
	int first = 0, last = 0;

	for (int i = 0; i < line.size(); i++)
	{
		if (start_str==false && start_tag == false && line[i] != '<' && line[i] != '>' && line[i] != ' ') // 문자가 들어오겠지?
		{
			start_str = true;
			first = i;
			continue;
		}

		else if (start_str == true)
		{
			if (i + 1 == line.size())
			{
				last = i;
				start_str = false;
				Reverse(first, last);
			}

			else if (line[i] == ' ' || line[i] == '<')
			{
				last = i - 1;
				start_str = false;
				Reverse(first, last);
			}
		}

		if (line[i] == '<') // 태그 시작.
			start_tag = true;

		if (start_tag == true)
		{
			if (line[i] == '>') // 태그 끝.
				start_tag = false;

			continue;
		}
	}
}

int main()
{
	getline(cin, line);
	Solve();

	cout << line;

	return 0;
}