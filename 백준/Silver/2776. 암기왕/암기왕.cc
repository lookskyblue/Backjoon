#include <iostream>
#include <set>

using namespace std;

void Input()
{
	int T, N, M;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		set<int> note;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;

			note.insert(x);
		}

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			int x;
			cin >> x;

			if (note.find(x) != note.end())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}
