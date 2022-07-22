#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

stack<string> s;

void DivideStr(string str, string& u, string& v)
{
    int left_count = 0;
    int right_count = 0;
    int i = 0;

    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') left_count++;
        if (str[i] == ')') right_count++;
        if (left_count == right_count) break;
    }

    u = str.substr(0, i + 1);
    v = str.substr(i + 1, str.size());

    //cout << "U: " << u << '\n';
    //cout << "V: " << v << '\n';
}

bool IsCorrectStr(string u)
{
    stack<char> s;

    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == ')')
        {
            if (s.empty() == true)
            {
                return false;
            }
            else
            {
                if (s.top() == u[i])
                {
                    return false;
                }

                else
                {
                    s.pop();
                }
            }
        }

        else
        {
            s.push(u[i]);
        }
    }

    return s.empty() == true ? true : false;
}

void RemoveAndReverse(string& u)
{
    // u의 사이즈가 안전한지 고려해야할까?

    u.erase(u.begin());
    u.erase(u.size() - 1);

    for (int i = 0; i < u.size(); i++)
    {
        u[i] = (u[i] == '(' ? ')' : '(');
    }
}

string Solve(string str)
{
    if (str == "") return str; // 1.

    string u, v;
    DivideStr(str, u, v); // 2.
    
    if (IsCorrectStr(u) == true) // 3. u가 올바른 괄호 문자열이라면
    {
        //cout << "U는 올바른 괄호 문자열" << "\n";
        return u + Solve(v);
    }
    else // 4. u가 올바른 괄호 문자열이 아니라면
    {
        string tmp = "("; // 4.1
        tmp += Solve(v); // 4.2
        tmp += ")"; // 4.3

        RemoveAndReverse(u); // 4.4
        tmp += u;

        return tmp;
    }
}

string solution(string p) {
    string answer = "";

    answer = Solve(p);
        
    return answer;
}