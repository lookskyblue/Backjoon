#include <iostream>
#include <stack>

using namespace std;

stack<char> left_s, right_s;

void Print()
{
    while(left_s.empty() == false)
    {
        right_s.push(left_s.top());
        left_s.pop();
    }
    
    while(right_s.empty() == false)
    {
        cout << right_s.top();
        right_s.pop();
    }
    
    cout << '\n';
}

void Solve(string str)
{
    while(left_s.empty() == false) left_s.pop();
    while(right_s.empty() == false) right_s.pop();
    
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '<')
        {
            if(left_s.empty() == false)
            {
                right_s.push(left_s.top());
                left_s.pop();
            }
        }
        
        else if(str[i] == '>')
        {
            if(right_s.empty() == false)
            {
                left_s.push(right_s.top());
                right_s.pop();
            }
        }
        
        else if(str[i] == '-')
        {
            if(left_s.empty() == false)
                left_s.pop();
        }
        
        else
        {
            left_s.push(str[i]);
        }
    }
    
    Print();
}

void Input()
{
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        
        Solve(str);
    }
}

int main()
{
    Input();
    
    return 0;
}