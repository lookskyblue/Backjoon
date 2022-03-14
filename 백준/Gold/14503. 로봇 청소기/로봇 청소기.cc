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

void Input()
{
	cin >> N >> M;
	cin >> pos_x >> pos_y >> dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void GetNextDirPos(int next_dir, int& next_x, int& next_y)
{
	if (next_dir == 0) next_x--;
	if (next_dir == 1) next_y++;
	if (next_dir == 2) next_x++;
	if (next_dir == 3) next_y--;
}

bool IsCleared(int next_x, int next_y)
{
	if (map[next_x][next_y] == 1 || cleared[next_x][next_y] == true) return true;

	return false;
}

void Solve()
{
	int rot_cnt = 0;

	while (1)
	{
		rot_cnt = 0;

		if (cleared[pos_x][pos_y] == false)
		{
			cleared[pos_x][pos_y] = true;
			clear_cnt++;
		}

		int next_dir = (dir + 4 - 1) % 4;
		int next_x = 0, next_y = 0;
		GetNextDirPos(next_dir, next_x, next_y);
		
		while (IsCleared(pos_x + next_x, pos_y + next_y) == true)
		{
			rot_cnt++;
			dir = (dir + 4 - 1) % 4;
			
			if (rot_cnt == 4) 
			{
				int next_x = 0, next_y = 0;
				GetNextDirPos((dir+4-2) % 4, next_x, next_y);

				if (map[pos_x + next_x][pos_y + next_y] == 1)
					return;

				pos_x += next_x;
				pos_y += next_y;
				rot_cnt = 0;
			}

			next_dir = (dir + 4 - 1) % 4;
			next_x = 0;
			next_y = 0;
			GetNextDirPos(next_dir, next_x, next_y);
		}

		pos_x += next_x;
		pos_y += next_y;
		dir = (dir + 4 - 1) % 4;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	Input();
	Solve();
	cout << clear_cnt;

	return 0;
}