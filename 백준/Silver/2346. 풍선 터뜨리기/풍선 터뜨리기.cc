#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;

void Solve()
{
	pair<int, int> tmp = dq.front();
	dq.pop_front();
	int idx = tmp.first;
	int card_num = tmp.second;

	cout << idx << " ";

	while (dq.empty() == false)
	{
		if (0 < card_num) // 양수
		{
			//cout << "CAR NUM: " << card_num << '\n';
			for (int i = 0; i < card_num - 1; i++)
			{
				pair<int, int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);

				//cout << "TEST: " << tmp.first << '\n';
			}

			pair<int, int> tmp = dq.front();
			dq.pop_front();

			cout << tmp.first << " ";

			card_num = tmp.second;
		}

		else
		{
			for (int i = 0; i < (card_num * -1); i++)
			{
				pair<int, int> tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}

			pair<int, int> tmp = dq.front();
			dq.pop_front();

			cout << tmp.first << " ";

			card_num = tmp.second;
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
