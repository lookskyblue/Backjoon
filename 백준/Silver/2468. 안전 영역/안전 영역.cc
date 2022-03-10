#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int map[100][100];
int copied_map[100][100];

void FindSection(int i, int j, int rain_amount, int n)
{
    if (i < 0 || i == n || j < 0 || j == n) return;
    if (map[i][j] <= rain_amount) return;

    map[i][j] = 0;

    FindSection(i + 1, j, rain_amount, n);
    FindSection(i - 1, j, rain_amount, n);
    FindSection(i, j + 1, rain_amount, n);
    FindSection(i, j - 1, rain_amount, n);
}

int main()
{
    int n, max_height = 0, max_section = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (max_height < map[i][j]) max_height = map[i][j];
        }
    }

    copy(&map[0][0], &map[0][0] + 10000, &copied_map[0][0]);

    for (int i = 0; i <= max_height; i++)
    {
        copy(&copied_map[0][0], &copied_map[0][0] + 10000, &map[0][0]);

        int now_section_count = 0;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (map[j][k] > i)
                {
                    FindSection(j, k, i, n);
                    now_section_count++;
                }
            }
        }

        max_section = max(max_section, now_section_count);
    }

    cout << max_section;

    return 0;
} 
