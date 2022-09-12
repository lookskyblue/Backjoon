#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct people
{
	string name;
	int y;
	int m;
	int d;
};

bool compare(people a, people b)
{
	if (a.y < b.y) return true;
	else if (a.y > b.y) return false;
	else
	{
		if (a.m < b.m) return true;
		else if (a.m > b.m) return false;
		else
		{
			if (a.d <= b.d) return true;
			else return false;
		}
	}
}

int main()
{
	vector<people> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		people p;
		cin >> p.name;
		cin >> p.d;
		cin >> p.m;
		cin >> p.y;

		vec.push_back(p);
	}

	sort(vec.begin(), vec.end(), compare);

	cout << vec[vec.size()-1].name << '\n';
	cout << vec.begin()->name << '\n';

	return 0;
}