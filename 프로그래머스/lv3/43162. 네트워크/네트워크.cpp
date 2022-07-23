#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<cstring>
#include<algorithm>
using namespace std;

bool visited[200];

void DFS(int idx, vector<vector<int>> computers)
{
    if (visited[idx] == true) return;
    else visited[idx] = true;

    for (int i = 0; i < computers[idx].size(); i++)
    {
        if (computers[idx][i] == 1)
            DFS(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i] == false)
        {
            DFS(i, computers);
            answer++;
        }
    }

    return answer;
}