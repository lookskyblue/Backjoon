#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <deque>
#include <string>
#include <cstdlib>

using namespace std;
int dist_sum;
int dg_pos, dg_off;
vector<pair<int, int>> s;


void North(int n, int m) // 상근이가 북쪽에 위치한 경우
{
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		int s_pos = s[i].first;
		int s_offset = s[i].second;

		if (s_pos == 1) dist_sum += abs(s_offset - dg_off);
		if (s_pos == 2) dist_sum += (m + min((dg_off + s_offset), (n - dg_off + n - s_offset)));
		if (s_pos == 3) dist_sum += (s_offset + dg_off);
		if (s_pos == 4) dist_sum += (s_offset + n - dg_off);
	}
}

void South(int n, int m)
{
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		int s_pos = s[i].first;
		int s_offset = s[i].second;

		if (s_pos == 1) dist_sum += (m + min((dg_off + s_offset), (n - dg_off + n - s_offset)));
		if (s_pos == 2) dist_sum += abs(s_offset - dg_off);
		if (s_pos == 3) dist_sum += (m - s_offset + dg_off);
		if (s_pos == 4) dist_sum += (m - s_offset + n - dg_off);
	}
}
// 1: 북 
// 2: 남 
// 3: 서 
// 4: 동
void West(int n, int m)
{
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		int s_pos = s[i].first;
		int s_offset = s[i].second;

		if (s_pos == 1) dist_sum += (s_offset + dg_off);
		if (s_pos == 2) dist_sum += (s_offset + m - dg_off);
		if (s_pos == 3) dist_sum += abs(s_offset - dg_off);
		if (s_pos == 4) dist_sum += (n + min((dg_off + s_offset), (m - dg_off + m - s_offset)));
	}
}

void East(int n, int m)
{
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		int s_pos = s[i].first;
		int s_offset = s[i].second;

		if (s_pos == 1) dist_sum += (n - s_offset + dg_off);
		if (s_pos == 2) dist_sum += (n - s_offset + m - dg_off);
		if (s_pos == 3) dist_sum += (n + min((dg_off + s_offset), (m - dg_off + m - s_offset)));
		if (s_pos == 4) dist_sum += abs(s_offset - dg_off);
	}
}

int main()
{
	int n, m, sc; // n 가로 m 세로
	cin >> n >> m >> sc;

	for (int i = 0; i < sc; i++)
	{
		int x, y;
		cin >> x >> y;
		s.push_back({ x, y });
	}

	cin >> dg_pos >> dg_off;

	if (dg_pos == 1) North(n, m);
	else if (dg_pos == 2) South(n, m);
	else if (dg_pos == 3) West(n, m);
	else East(n, m);

	cout << dist_sum;

	return 0;
}