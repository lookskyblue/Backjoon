#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, pair<bool, string>> m;
    queue<pair<string, bool>> id_q;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> divied_record;
        string tmp = record[i];
        char* str = &tmp[0];
        char* ptr = strtok(str, " ");

        while (ptr != NULL)
        {
            divied_record.push_back(ptr);
            ptr = strtok(NULL, " ");
        }

        if (divied_record[0] == "Enter")
        {
            m[divied_record[1]] = pair<bool, string>(true, divied_record[2]);
            id_q.push(make_pair(divied_record[1], true));
        }
        else if(divied_record[0] == "Leave")
        {
            m[divied_record[1]].first = false;
            id_q.push(make_pair(divied_record[1], false));
        }
        else
        {
            m[divied_record[1]].second = divied_record[2];
        }
    }

    while(id_q.empty() == false)
    {
        string result = m[id_q.front().first].second + "님이 " + ((id_q.front().second == true) ? "들어왔습니다." : "나갔습니다.");

        id_q.pop();
        answer.push_back(result);
    }

    return answer;
}