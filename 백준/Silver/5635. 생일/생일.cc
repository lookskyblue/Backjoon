#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Person
{
	string name;
	int day;
	int month;
	int year;
};

bool compare(const Person& a, const Person& b)
{
	if (a.year < b.year) return true;
	else if (a.year > b.year) return false;
	else
	{
		if (a.month < b.month) return true;
		else if (a.month > b.month) return false;
		else
		{
			if (a.day < b.day) return true;
			else return false;
		}
	}
}

void Solve()
{
	int N;
	cin >> N;

	vector<Person> people;
	people.reserve(N);

	for (int i = 0; i < N; i++)
	{
		Person person = Person();
		cin >> person.name;
		cin >> person.day >> person.month >> person.year;

		people.push_back(person);
	}

	sort(people.begin(), people.end(), compare);

	cout << people[N-1].name << '\n' << people[0].name;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}