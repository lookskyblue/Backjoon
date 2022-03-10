#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K, S, X, Y;
int map[201][201];
bool is_spread[201][201];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void Input()
{
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	cin >> S >> X >> Y;
}

void Print()
{
	cout << map[X][Y];

	return;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << map[i][j] << " ";

		cout << endl;
	}
}

void Solve()
{
	for (int t = 0; t < S; t++)
	{
		memset(is_spread, false, sizeof(is_spread));

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] != 0 && is_spread[i][j] == false) // 바이러스가 있고 아직 퍼지지 않았다면 퍼트리자
				{
					// 퍼트려
					is_spread[i][j] = true;

					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (1 <= nx && nx <= N && 1<= ny && ny <= N&& map[nx][ny] == 0) // 상하좌우가 비어 있다면
						{
							int can_spread = true;

							for (int p = 0; p < 4; p++)
							{
								int nnx = nx + dx[p];
								int nny = ny + dy[p];

								if (1 <= nnx && nnx <= N && 1 <= nny && nny <= N) 
								{
									if(is_spread[nnx][nny] == false && 1 <= map[nnx][nny] && map[nnx][nny] < map[i][j])
									{
										can_spread = false;
										break;
									}
								}
							}

							if (can_spread == true)
							{
								map[nx][ny] = map[i][j];
								is_spread[nx][ny] = true;

								if (map[X][Y] > 0) return ;
							}
						}
					}

				}
			}
		}
	}
}

int main()
{
	Input();
	Solve();
	Print();

	return 0;
}