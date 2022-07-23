#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<cstring>
#include<algorithm>
using namespace std;

bool visited[200];

void DFS(int from, vector<vector<int>> computers)
{
    if (visited[from] == true) return;
    else visited[from] = true;

    for (int to = 0; to < computers[from].size(); to++)
    {
        if (computers[from][to] == 1)
            DFS(to, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    
    for (int from = 0; from < computers.size(); from++)
    {
        if (visited[from] == false)
        {
            DFS(from, computers);
            answer++;
        }
    }

    return answer;
}