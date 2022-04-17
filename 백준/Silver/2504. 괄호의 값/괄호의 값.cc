#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
int ans;

void Solve()
{
    bool is_closing = false;
    int tmp = 1;
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            is_closing = false;
            tmp *=2;
            s.push(str[i]);
        }
        
        else if(str[i] == '[')
        {
            is_closing = false;
            tmp*=3;
            s.push(str[i]);
        }
        
        else if(str[i] == ')')
        {
            if(s.empty() == true || s.top() != '(')
            {
                cout << "0";
                return;
            }
            
            else
            {
                if(is_closing == false)
                    ans += tmp;
                
                tmp /= 2;
                s.pop();
                is_closing = true;
            }
        }
        
        else if(str[i] == ']')
        {
            if(s.empty() == true || s.top() != '[')
            {
                cout << "0";
                return;
            }
            
            else
            {
                if(is_closing == false)
                    ans += tmp;
                
                tmp /=3;
                s.pop();
                is_closing = true;
            }
        }
    }
    
    if(s.empty() == false) cout << "0";
    else cout << ans;
}

int main()
{
    Solve();

    return 0;
}