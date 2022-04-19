#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

map<string, bool, greater<string>> employee_log; // 회사면 값이 true
string user_state;

string split(string user_state)
{
	string name;

	for (int i = 0; i < user_state.size(); i++)
	{
		if (user_state[i] == ' ')
			break;

		name += user_state[i];
	}

	return name;
}

void RegisterEmployeeCommuteState(string name)
{
	map<string, bool>::iterator itr = employee_log.find(name);

	if (itr == employee_log.end())
		employee_log.insert({ name, true });
	else
	{
		bool state = itr->second;
		employee_log.at(name) = !state;
	}
}

void Solve()
{
	for (map<string, bool>::iterator itr = employee_log.begin(); itr != employee_log.end(); itr++)
		if (itr->second == true)
			cout << itr->first << '\n';
}

void Input()
{
	int N;
	cin >> N;

	getline(cin, user_state); // cin은 개행문자 전까지 읽어서 \n이 남은걸 getline으로 받아줘.
	// getline은 개행문자 까지 읽음.

	for (int i = 0; i < N; i++)
	{
		getline(cin, user_state);
		string name = split(user_state);

		RegisterEmployeeCommuteState(name);
	}

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}