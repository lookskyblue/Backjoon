#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int N;
vector<int> v;
int opt = 2000000000;
int first_s, second_s;

void BS(int first_solution, int first_idx)
{
	//if (first_solution == -1000) cout << "First sol: " << -1000 << '\n';

	int copy_first_solution = abs(first_solution);

	int low = first_idx + 1;
	int mid = 0;
	int high = v.size();

	while (low < high)
	{
		mid = (low + high) / 2;

		//if (first_solution == -1000) cout << "low: " <<low <<", high: "<<high << ", mid: " << mid << ", v[mid]: " << v[mid] << '\n';

		if (copy_first_solution <= v[mid])
		{
			high = mid;

			//if (abs(first_solution + v[mid]) < abs(opt))
			//{
			//	opt = first_solution + v[mid];
			//	first_s = first_solution;
			//	second_s = v[mid];

			//	//if (first_solution == -1000) cout << "opt: " << opt << '\n';
			//	//if (first_solution == -1000) cout << "first_s: " << first_s << '\n';
			//	//if (first_solution == -1000) cout << "second_s: " << second_s << '\n';
			//}
		}

		else
			low = mid + 1;

		if (abs(first_solution + v[mid]) < abs(opt))
		{
			opt = first_solution + v[mid];
			first_s = first_solution;
			second_s = v[mid];

			//if (first_solution == -1000) cout << "opt: " << opt << '\n';
			//if (first_solution == -1000) cout << "first_s: " << first_s << '\n';
			//if (first_solution == -1000) cout << "second_s: " << second_s << '\n';
		}
	}

	/*if (first_solution == -1000) cout << "out of while mid: " << mid << '\n';

	if (abs(first_solution + v[mid]) < abs(opt))
	{
		opt = first_solution + v[mid];
		first_s = first_solution;
		second_s = v[mid];

		if (first_solution == -1000) cout << "opt: " << opt << '\n';
		if (first_solution == -1000) cout << "first_s: " << first_s << '\n';
		if (first_solution == -1000) cout << "second_s: " << second_s << '\n';
	}*/
}

void Solve()
{
	for (int i = 0; i < v.size() - 1; i++)
		BS(v[i], i);

	cout << first_s << ' ' << second_s;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}