#include <iostream>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

map<string, int> title;

void Input()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string title_str;
		cin >> title_str;

		map<string, int>::iterator itr = title.find(title_str);

		if (itr != title.end()) itr->second++;
		else title.insert({ title_str, 1 });
	}

	int best_book_count = 0;
	string best_book;

	for (map<string, int>::iterator itr = title.begin(); itr != title.end(); itr++)
	{
		if (best_book_count < itr->second)
		{
			best_book_count = itr->second;
			best_book = itr->first;
		}
	}

	cout << best_book;
}

int main()
{
	Input();

	return 0;
}
