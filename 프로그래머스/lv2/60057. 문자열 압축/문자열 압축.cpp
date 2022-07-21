#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        int cnt = 1;
        string prev = s.substr(0, i);
        string tmp = "";

        for (int j = i; j < s.size(); j += i)
        {
            if (prev == s.substr(j, i)) cnt++;

            else
            {
                if (cnt > 1) tmp += to_string(cnt);

                tmp += prev;
                prev = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) tmp += to_string(cnt);
        tmp += prev;
        if (tmp.size() < answer) answer = tmp.size();
    }

    return answer;
}