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

struct compare {
	bool operator()(int a, int b)
	{
		if (abs(a) > abs(b)) return true;
		else if (abs(a) == abs(b))
			if (a > b) return true;

		return false;
	}
};

priority_queue<int, vector<int>, compare> pq;

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		//x = abs(x);

		if (x == 0)
		{
			if (pq.empty() == true)
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}

		else
			pq.push(x);
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