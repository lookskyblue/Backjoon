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

map<string, int> tree_m;

void Input()
{
	int n = 0;
	int total_tree = 0;
	string tree;

	while (getline(cin, tree))
	{
		map<string, int>::iterator itr = tree_m.find(tree);

		if (itr != tree_m.end())
			itr->second++;

		else
			tree_m.insert({ tree, 1 });

		total_tree++;
	}

	int tree_m_size = tree_m.size();

	for (map<string, int>::iterator itr = tree_m.begin(); itr != tree_m.end(); itr++)
	{
		double percentage = ((double)itr->second / total_tree) * 100;
		percentage = round(percentage * 10000) / 10000;
		
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