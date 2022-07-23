#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<cstring>
#include<algorithm>
using namespace std;

int answer = 9999;
vector<string> s_words;
bool is_using[200];
string s_target;

bool IsOverTwoDiff(string begin, string next)
{
    int diff_cnt = 0;

    for (int i = 0; i < begin.size(); i++)
    {
        if (begin[i] != next[i]) diff_cnt++;
    }

    return diff_cnt >= 2 ? true : false;
}

void DFS(int cnt, string begin)
{
    if (begin == s_target) // 같다면
    {
        answer = min(answer, cnt);
        return;
    }

    if (cnt == s_words.size())
    {
        return;
    }

    for (int i = 0; i < s_words.size(); i++)
    {
        if (is_using[i] == true) continue;
        if (IsOverTwoDiff(begin, s_words[i]) == true) continue;
        
        is_using[i] = true;
        DFS(cnt + 1, s_words[i]);
        is_using[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {

    s_words = words;
    s_target = target;

    DFS(0, begin);

    return answer == 9999 ? 0 : answer;
}