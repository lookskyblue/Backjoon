#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int map[20][20];

class Dice
{
	private :
		int _maxX, _maxY;
		int _nowX, _nowY = 0;
		int _diceMap[6] = { 0 };

		bool CanRoll(int dir)
		{
			switch (dir)
			{
				case 1: { return _nowY < _maxY; } // 동
				case 2: { return 0 < _nowY; } // 서
				case 3: { return 0 < _nowX; } // 북
				case 4: { return _nowX < _maxX; } // 남
			}
		}

		void RealRoll(int dir)
		{
			switch (dir)
			{
				case 1: // 동
				{
					_nowY++;

					int temp0 = _diceMap[0];
					int temp2 = _diceMap[2];
					int temp3 = _diceMap[3];
					int temp5 = _diceMap[5];

					_diceMap[3] = temp0;
					_diceMap[0] = temp2;
					_diceMap[5] = temp3;
					_diceMap[2] = temp5;

					break;
				}
				case 2: // 서 
				{
					_nowY--;

					int temp0 = _diceMap[0];
					int temp2 = _diceMap[2];
					int temp3 = _diceMap[3];
					int temp5 = _diceMap[5];

					_diceMap[2] = temp0;
					_diceMap[5] = temp2;
					_diceMap[0] = temp3;
					_diceMap[3] = temp5;

					break;
				}
				case 3: // 북
				{
					_nowX--;

					int temp0 = _diceMap[0];
					int temp1 = _diceMap[1];
					int temp4 = _diceMap[4];
					int temp5 = _diceMap[5];

					_diceMap[1] = temp0;
					_diceMap[5] = temp1;
					_diceMap[0] = temp4;
					_diceMap[4] = temp5;

					break;
				}
				case 4: // 남 
				{
					_nowX++;

					int temp0 = _diceMap[0];
					int temp1 = _diceMap[1];
					int temp4 = _diceMap[4];
					int temp5 = _diceMap[5];

					_diceMap[4] = temp0;
					_diceMap[0] = temp1;
					_diceMap[5] = temp4;
					_diceMap[1] = temp5;

					break;
				}
			}
		}

		void InteractWithMap()
		{
			if (map[_nowX][_nowY] == 0)
			{
				map[_nowX][_nowY] = _diceMap[0];
			}
			else
			{
				_diceMap[0] = map[_nowX][_nowY];
				map[_nowX][_nowY] = 0;
			}
		}

	public :
		Dice(int maxX, int maxY, int nowX, int nowY)
		{
			_maxX = maxX;
			_maxY = maxY;
			_nowX = nowX;
			_nowY = nowY;
		}
		void Roll(int dir)
		{
			if (CanRoll(dir) == false)
			{
				return;
			}

			RealRoll(dir);
			InteractWithMap();

			cout << _diceMap[5] << '\n';
		}
};

void Solve()
{
	int N, M, x, y, K = 0;
	cin >> N >> M >> x >> y >> K;

	N--;
	M--;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	Dice dice = Dice(N, M, x, y);

	for (int i = 0; i < K; i++)
	{
		int dir;
		cin >> dir;

		dice.Roll(dir);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}