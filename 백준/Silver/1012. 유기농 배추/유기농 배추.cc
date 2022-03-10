#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int map[50][50];
int visited[50][50];

int FindContinueCabbge(int x, int y, int height, int width)
{
    if (x < 0 || height <= x || y < 0 || width <= y) return 0;
    if (map[x][y] == 0) return 0;
    if (visited[x][y] == 1) return 0;
    
    visited[x][y] = 1;

    // 동서남북 재귀

    return ( 1 | FindContinueCabbge(x - 1, y, height, width) | 
                    FindContinueCabbge(x + 1, y, height, width) |
                        FindContinueCabbge(x, y - 1, height, width) |
                            FindContinueCabbge(x, y + 1, height, width)
            );
}

int main()
{
    int t, width, height, cabbage_count;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> width >> height >> cabbage_count;
        // map, visited 초기화 해줄 것.
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        int total_earthworm = 0;

        for (int j = 0; j < cabbage_count; j++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        // t번째 맵에 데이터 다 저장했으면 본 로직 수행

        for (int x = 0; x < height; x++)
        {
            for (int y = 0; y < width; y++)
            {
                if (FindContinueCabbge(x, y, height, width) == 1)
                {
                    total_earthworm++;
                }
            }
        }

        cout << total_earthworm << endl;
    }

    return 0;
} 
