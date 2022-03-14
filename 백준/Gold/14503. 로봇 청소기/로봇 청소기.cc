#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int pos_x, pos_y, dir;
int map[51][51];
bool cleared[51][51];
int clear_cnt = 0;
int rot_x_y[2][4] = { { -1, 0, 1, 0 }, {0, 1, 0, -1} };

void Input()
{
	cin >> N >> M;
	cin >> pos_x >> pos_y >> dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

bool IsCleared(int next_x, int next_y)
{
	if (map[next_x][next_y] == 1 || cleared[next_x][next_y] == true) 
		return true;

	return false;
}

void Solve()
{
	while (1)
	{
		cleared[pos_x][pos_y] = true;
		clear_cnt++;

		int rot_cnt = 0;
		int next_dir = (dir + 4 - 1) % 4;

		while (IsCleared(pos_x + rot_x_y[0][next_dir], pos_y + rot_x_y[1][next_dir]) == true)
		{
			rot_cnt++;
			dir = (dir + 4 - 1) % 4;

			if (rot_cnt == 4)
			{
				int tmp_dir = (dir + 4 - 2) % 4;
				if (map[pos_x + rot_x_y[0][tmp_dir]][pos_y + rot_x_y[1][tmp_dir]] == 1)
				{
					cout << clear_cnt;
					return;
				}

				pos_x += rot_x_y[0][tmp_dir];
				pos_y += rot_x_y[1][tmp_dir];
				rot_cnt = 0;
			}

			next_dir = (dir + 4 - 1) % 4;
		}

		pos_x += rot_x_y[0][next_dir];
		pos_y += rot_x_y[1][next_dir];
		dir = (dir + 4 - 1) % 4;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();

	return 0;
}
