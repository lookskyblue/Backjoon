#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#define EMPTY 0
#define APPLE 1
#define ME 2

using namespace std;

int N;
int map[101][101];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int dir = 2;

queue<pair<int, char>> rot;
deque<pair<int, int>> body;

void Input()
{
	int K, R;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = APPLE;
	}

	cin >> R;
	
	for (int i = 0; i < R; i++)
	{
		int t;
		char r;
		cin >> t >> r;
		rot.push({ t, r });
	}

	map[1][1] = ME;
	body.push_back({ 1, 1 });
}

void Solve()
{
	int time = 0;

	while (++time)
	{
		int head_x = body.back().first;
		int head_y = body.back().second;
		
		head_x += dx[dir];
		head_y += dy[dir];

		if (head_x < 1 || head_x > N || head_y < 1 || head_y > N || map[head_x][head_y] == ME)
			break;

		body.push_back({ head_x, head_y });

		if(map[head_x][head_y] == EMPTY) // 사과가 없다면
		{
			int tail_x = body.front().first;
			int tail_y = body.front().second;

			body.pop_front();
			map[tail_x][tail_y] = EMPTY;
		}

		map[head_x][head_y] = ME;

		if (rot.size() != 0 && rot.front().first == time) // 2. 방향 전환 체크
		{
			dir = (rot.front().second == 'D') ? ((dir + 4 + 1) % 4) : ((dir + 4 - 1) % 4);
			rot.pop();
		}
	}

	cout << time;
}

int main()
{
	Input();
	Solve();

	return 0;
}