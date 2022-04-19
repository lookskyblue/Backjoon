#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

map<string, string> account;
string site_password;

void AddAccount(string site_password)
{
	string site, password;

	int i = 0;

	for (i = 0; i < site_password.size(); i++)
	{
		if (site_password[i] == ' ')
			break;

		site += site_password[i];
	}

	i++;

	for (; i < site_password.size(); i++)
	{
		password += site_password[i];
	}

	account.insert({ site, password });
}

void Solve(string site)
{
	map<string, string>::iterator itr = account.find(site);

	if (itr != account.end())
		cout << itr->second << '\n';
}

void Input()
{
	int N, M;
	cin >> N >> M;
	getline(cin, site_password);

	for (int i = 0; i < N; i++)
	{
		getline(cin, site_password);
		AddAccount(site_password);
	}

	for (int i = 0; i < M; i++)
	{
		string site;
		getline(cin, site);

		Solve(site);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}