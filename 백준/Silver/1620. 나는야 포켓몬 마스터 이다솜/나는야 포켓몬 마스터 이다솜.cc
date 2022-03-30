#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

map<string, int> monster_book;
vector<string> monster_book_v;

void Solve()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		monster_book.insert({ name, i + 1 });
		monster_book_v.push_back(name);
	}

	for (int i = 0; i < M; i++)
	{
		string x;
		cin >> x;
		
		if (atoi(x.c_str()) == 0) // 문자
		{
			map<string, int>::iterator itr = monster_book.find(x);
		
			if (itr != monster_book.end())
			{
				cout << itr->second << '\n';
			}
		}

		else
		{
			cout << monster_book_v[atoi(x.c_str()) - 1] << '\n';
			/*for (map<string, int>::iterator itr = monster_book.begin(); itr != monster_book.end(); itr++)
			{
				if (itr->second == atoi(x.c_str()))
				{
					cout << itr->first << '\n';
					break;
				}
			}*/
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}