#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

bool visited[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int max_x = 0, max_y = 0;
int max_size_of_one_area = 0;

void DFS(int y, int x, int color, int& paint_cnt, vector<vector<int>>& pic)
{
    max_size_of_one_area = max(max_size_of_one_area, paint_cnt);

    if (visited[y][x] == true) return;
    if (pic[y][x] != color) return;
    
    visited[y][x] = true;
    ++paint_cnt;
    max_size_of_one_area = max(max_size_of_one_area, paint_cnt);

    for (int k = 0; k < 4; k++)
    {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (0 <= next_x && next_x < max_x && 0 <= next_y && next_y < max_y)
        {
            DFS(next_y, next_x, color, paint_cnt, pic);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    max_size_of_one_area = 0;
    max_x = n;
    max_y = m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false && picture[i][j] != 0)
            {
                number_of_area++;
                int paint_cnt = 0;

                DFS(i, j, picture[i][j], paint_cnt, picture);
            }
        }
    }

    memset(visited, false, sizeof(visited));

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}