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

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());

    for (int i = citations[0]; i > 0; i--)
    {
        int h = i;
        int h_up_cnt = 0;

        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= h) h_up_cnt++;
        }

        if (h_up_cnt >= h)
        {
            answer = max(h, answer);
            break;
        }
    }

    return answer;
}