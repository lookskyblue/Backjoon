#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <cmath>

using namespace std;

int N, L, R;
int map[50][50];
bool v[50][50];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<pair<int, int>>> union_group;

void Input()
{
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
}

void DFS(int x, int y)
{
    vector<pair<int, int>> union_each;
    stack<pair<int, int>> s;
    
    union_each.push_back({x, y});
    s.push({x, y});
    
    v[x][y] = true;
    
    while(s.empty() == false)
    {
        int now_x = s.top().first;
        int now_y = s.top().second;
        s.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            
            if(0 <= nx && nx < N && 0 <= ny && ny < N && v[nx][ny] == false)
            {
                int gap = map[now_x][now_y] - map[nx][ny];
                
                if(L <= abs(gap) && abs(gap) <= R)
                {
                    v[nx][ny] = true;
                    s.push({nx, ny});
                    union_each.push_back({nx, ny});
                }
            }
        }
    }
    
    if(union_each.size() > 1)
        union_group.push_back(union_each);
}

void Solve()
{
    int day = 0;
    
    while(++day)
    {
        for(int i = 0; i < 50; i++)
            memset(v[i], false, sizeof(v[i]));
        
        union_group.clear();
    
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(v[i][j] == false)
                    DFS(i, j);
    
        if(union_group.size() == 0)
        {
            cout << day - 1;
            return;
        }
        
        else
        {
            for(int i = 0; i < union_group.size(); i++)
            {
                int sum = 0;
                
                for(int j = 0; j < union_group[i].size(); j++)
                {
                    int x = union_group[i][j].first;
                    int y = union_group[i][j].second;
                    
                    sum += map[x][y];
                }
                
                int average = sum / union_group[i].size();
                
                for(int j = 0; j < union_group[i].size(); j++)
                {
                    int x = union_group[i][j].first;
                    int y = union_group[i][j].second;
                    
                    map[x][y] = average;
                }
            }
        }
    }
}

int main()
{
    Input();
    Solve();

    return 0;
}