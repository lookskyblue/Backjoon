#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        string tmp = "";
        string prev = s.substr(0, i);
        int cnt = 1;

        for (int j = i; j < s.size(); j += i)
        {
            if (prev == s.substr(j, i))
            {
                cnt++;
            }
            else
            {
                if (cnt > 1)
                {
                    tmp += to_string(cnt);
                }

                tmp += prev;
                prev = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1)
        {
            tmp += to_string(cnt);
        }

        tmp += prev;

        if (answer > tmp.size()) answer = tmp.size();
    }

    return answer;
}
