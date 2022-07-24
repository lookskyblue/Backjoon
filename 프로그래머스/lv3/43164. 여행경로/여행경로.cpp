#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<map> 
#include<set> 
#include<cstring>
#include<algorithm>
using namespace std;

vector<string> answer;
bool visited[10000];

bool DFS(string from, int used_ticket_cnt, vector<vector<string>>& tickets)
{
    answer.push_back(from);

    if (used_ticket_cnt == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i] == true || from != tickets[i][0]) continue;

        visited[i] = true;
        bool result = DFS(tickets[i][1], used_ticket_cnt + 1, tickets);

        if (result == true) return true;
        else
        {
            visited[i] = false;
        }
    }

    answer.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", 0, tickets);

    return answer;
}