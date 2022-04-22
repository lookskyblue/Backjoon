#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>

using namespace std;

map<string, float> tree_m;

void Input()
{
	int n = 0;
	int total_tree = 0;
	string tree;

	while (getline(cin, tree))
	{
		tree_m[tree]++;
		total_tree++;
	}

	for (map<string, float>::iterator itr = tree_m.begin(); itr != tree_m.end(); itr++)
	{
		float percentage = (itr->second / total_tree) * 100;

		cout << fixed;
		cout.precision(4);
		cout << itr->first << " " << percentage << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}