#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<cstring>
#include<algorithm>
using namespace std;

int map[100][100];
pair<int, int> parent[100][100];
int answer;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

void BFS(int m, int n, int max_m, int max_n)
{
    queue<pair<int, int>> s;
    s.push({ m, n });
    
    map[m][n] = 0;
    parent[m][n] = { m,n };

    bool is_find_exit = false;

    while (s.empty() == false)
    {
        int now_m = s.front().first;
        int now_n = s.front().second;
        s.pop();

        if (now_m == max_m - 1 && now_n == max_n - 1)
        {
            is_find_exit = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nm = now_m + dir_y[i];
            int nn = now_n + dir_x[i];

            if (0 <= nm && nm < max_m && 0 <= nn && nn < max_n && map[nm][nn] == 1)
            {
                s.push({ nm, nn });
                map[nm][nn] = 0;
                parent[nm][nn] = { now_m, now_n };
            }
        }
    }

    if (is_find_exit == true)
    {
        int x = max_n - 1;
        int y = max_m - 1;
        answer = 1;

        while ((x == 0 && y == 0) == false)
        {
            answer++;
         
            pair<int, int> p = parent[y][x];
            y = p.first;
            x = p.second;
        }
    }

    else answer = -1;
}

int solution(vector<vector<int> > maps)
{
    for (int m = 0; m < maps.size(); m++)
    {
        for (int n = 0; n < maps[m].size(); n++)
        {
            map[m][n] = maps[m][n];
        }
    }

    BFS(0, 0, maps.size(), maps[0].size());

    return answer;
}