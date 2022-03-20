#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int T, n;
int arr[100000];
int front, rear;

void Split(string s, string divid)
{
    int i = 0;
    char* c = strtok((char*)s.c_str(), (char*)divid.c_str());
    while(c)
    {
        arr[i++] = atoi(c);
        c = strtok(NULL, (char*)divid.c_str());
    }
}

void Solve()
{
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        string p, arr_str;
        cin >> p >> n >> arr_str;
        int num_count = n;
        rear = n;
        front = 0;
        
        memset(arr, 0, sizeof(int) * 100000);
        Split(arr_str, "[,]");
        
        bool is_error = false;
        bool is_r = false;
        int p_size = p.size();
        
        for(int j = 0; j < p_size; j++)
        {
            if(p[j] == 'R') is_r = is_r == true ? false : true;
            
            else
            {
                if(num_count-- == 0)
                {
                    is_error = true;
                    cout << "error" << '\n';
                    break;
                }
                
                else
                {
                    if(is_r == false) front++;
                    else rear--;
                }
            }
        }
        
        if(is_error == false)
        {
            if(is_r == true) reverse(arr + front, arr + rear);
                
            cout << "[";
            
            for(int j = front; j < rear; j++)
            {
                cout << arr[j];
                if(j + 1 != rear) cout <<",";
            }
            cout << "]" << '\n';
        }
    }
}

int main()
{
    Solve();

    return 0;
}