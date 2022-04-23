#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>

using namespace std;

void Solve(string str, int t)
{
	int count = 0;

	cout << t << ". ";

	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty() == true)
		{
			if (str[i] == '}') count++;

			s.push('{');
		}

		else
		{
			if (str[i] == '}')
			{
				s.pop();
			}

			else
				s.push('{');
		}
	}

	while (s.empty() == false)
	{
		count++;

		s.pop();
		s.pop();
	}

	cout << count << '\n';
}

void Input()
{
	int t = 0;
	string str;

	while (getline(cin, str))
	{
		if (str[0] == '-') break;
		
		Solve(str, ++t);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}