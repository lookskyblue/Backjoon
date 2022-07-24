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

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> all(n + 2, 1);

    for (int i = 0; i < lost.size(); i++) all[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++) all[reserve[i]]++;
    for (int i = 1; i < all.size(); i++)
    {
        if (all[i] == 0)
        {
            if (all[i - 1] == 2)
                all[i] = all[i - 1] = 1;
            else if (all[i + 1] == 2)
                all[i] = all[i + 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        if (all[i] != 0) answer++;

    return answer;
}