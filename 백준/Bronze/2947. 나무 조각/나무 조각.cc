#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int pieceArr[5];

void Solve()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> pieceArr[i];
	}

	bool needLoop = true;

	while (needLoop)
	{
		needLoop = false;

		for (int i = 0; i < 4; i++)
		{
			if (pieceArr[i] > pieceArr[i + 1])
			{
				int temp = pieceArr[i];
				pieceArr[i] = pieceArr[i + 1];
				pieceArr[i + 1] = temp;

				for (int j = 0; j < 5; j++)
				{
					cout << pieceArr[j] << " ";
				}

				cout << '\n';
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (pieceArr[i] != i+1)
			{
				needLoop = true;
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}