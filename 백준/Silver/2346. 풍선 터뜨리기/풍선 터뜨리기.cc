#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;

void Solve()
{
	while (dq.empty() == false)
	{
		pair<int, int> tmp = dq.front();
		dq.pop_front();
		cout << tmp.first << " ";
		int card_num = tmp.second;

		if (dq.empty() == true)
			return;

		if (0 < card_num) // 양수
		{
			for (int i = 0; i < card_num - 1; i++)
			{
				pair<int, int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}

		else
		{
			for (int i = 0; i < (card_num * -1); i++)
			{
				pair<int, int> tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}

	}
}

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		dq.push_back(make_pair( i + 1, x ));
	}

	Solve();
}

int main()
{
	Input();

	return 0;
}
