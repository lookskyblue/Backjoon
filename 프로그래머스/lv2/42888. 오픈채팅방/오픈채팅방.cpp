#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    queue<pair<string, bool>> q;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> each_log;
        string full_log = record[i];

        char* str = &full_log[0];
        char* ptr = strtok(str, " ");

        while (ptr != NULL)
        {
            each_log.push_back(ptr);
            ptr = strtok(NULL, " ");
        }

        if (each_log[0] == "Enter")
        {
            m[each_log[1]] = each_log[2];
            q.push(make_pair(each_log[1], true));
        }

        if (each_log[0] == "Leave")
        {
            q.push(make_pair(each_log[1], false));
        }

        if (each_log[0] == "Change")
        {
            m[each_log[1]] = each_log[2];
        }
    }

    while (q.empty() == false)
    {
        string tmp = m[q.front().first] + "님이 ";
        tmp += (q.front().second == true ? "들어왔습니다." : "나갔습니다.");
        answer.push_back(tmp);
        
        q.pop();
    }

    return answer;
}