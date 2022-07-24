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

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int now_boat_kg = 0;

    int start = 0;
    int last = people.size() - 1;

    while ((start > last) == false)
    {
        if (start == last)
        {
            answer++;
            break;
        }

        now_boat_kg += people[last];
        last--;

        if (now_boat_kg + people[start] <= limit)
        {
            answer++;
            start++;
            now_boat_kg = 0;
        }

        else
        {
            answer++;
            now_boat_kg = 0;
        }
    }

    return answer;
}