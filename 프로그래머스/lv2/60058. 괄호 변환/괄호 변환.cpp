#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

void GetBalanceStr(string& u, string& v, string p)
{
    int right_cnt = 0;
    int left_cnt = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(') right_cnt++;
        if (p[i] == ')') left_cnt++;
        if (right_cnt == left_cnt)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1, p.size() - i);
            break;
        }
    }
}

bool IsRightStr(string p)
{
    stack<char> s;

    s.push(p[0]);

    for (int i = 1; i < p.size(); i++)
    {
        if (p[i] == '(') s.push(p[i]);
        if (p[i] == ')')
        {
            if (s.empty() == true) return false;
            if (s.top() == ')') return false;
            if (s.top() == '(') s.pop();
        }
    }

    return s.empty() == true ? true : false;
}

void TrimStr(string& p)
{
    p.erase(p.begin());
    p.erase(p.end() - 1);

    for (int i = 0; i < p.size(); i++)
    {
        p[i] = (p[i] == '(' ? ')' : '(');
    }
}

string Solve(string p)
{
    if (p.empty() == true) return p; // 1.
    
    string u, v;

    GetBalanceStr(u, v, p); // 2.

    if (IsRightStr(u) == true) // 3.
    {
        return u + Solve(v);
    }

    else
    {
        string tmp = '(' + Solve(v) + ')';
        TrimStr(u);
        return tmp + u;
    }
}

string solution(string p) {
    return Solve(p);
}