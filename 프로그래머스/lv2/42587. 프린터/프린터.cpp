#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(pair<int, int>(priorities[i], i));
        q.push(pair<int, int>(priorities[i], i));
    }

    while (q.empty() == false)
    {
        if (q.front().first < pq.top().first)
        {
            q.push(q.front());
            q.pop();
        }

        else
        {
            answer++;

            if (q.front().second == location)
                break;

            pq.pop(); 
            q.pop();
        }
    }

    return answer;
}