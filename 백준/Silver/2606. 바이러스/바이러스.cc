#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	
	stack<int> s;

	int map[101][101] = { 0 };
	int visited[101] = { 0 };
	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	s.push(1);

	while (!s.empty())
	{
		int zone = s.top();
		s.pop();
		visited[zone] = 1;

		for (int i = 0; i <= n; i++)
		{
			if ((map[zone][i] == 1  || map[i][zone] == 1)&& visited[i] == 0)
			{
				// 길이 있고 최초 방문일 때. 푸쉬하겠다.
				s.push(i);
			}
		}
	}

	int count = 0;

	for (int i = 2; i <= n; i++)
	{
		//printf("%d", visited[i]);
		if (visited[i] == 1)
			count++;
	}

	printf("%d", count);

	return 0;
}