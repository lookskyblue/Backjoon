#include <bitset>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visited[101][101] = { false };
char map[101][101];

void GetAlphaCount(char alpha, int x, int y, int n, int m, int &w)
{
	// 맵의 유효 범위인지 파악, alpha가 똑같은지 파악하고. 최초 방문인지 파악.
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (alpha != map[x][y]) return;
	if (visited[x][y] == true) return;

	visited[x][y] = true;
	w++;

	GetAlphaCount(alpha, x + 1, y, n, m, w);
	GetAlphaCount(alpha, x - 1, y, n, m, w);
	GetAlphaCount(alpha, x, y + 1, n, m, w);
	GetAlphaCount(alpha, x, y - 1, n, m, w);

}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		string line;

		cin >> line;

		for (int j = 0; j < n; j++)
		{
			map[i][j] = line[j];
		}
	}

	int total_w_count = 0;
	int total_b_count = 0;


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int w = 0, b=0;

			GetAlphaCount('W', i, j, n, m, w);
			GetAlphaCount('B', i, j, n, m, b);

			total_w_count += w * w;
			total_b_count += b * b;

		}
	}

	cout << total_w_count << " " << total_b_count;

	return 0;
}