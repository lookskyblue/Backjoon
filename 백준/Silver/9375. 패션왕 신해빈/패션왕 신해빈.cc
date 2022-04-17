#include <iostream>
#include <map>

using namespace std;

void Solve()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        map<string, int> dress;
        int n;
        cin >> n;
        
        while(n--)
        {
            string type, cloth;
            cin >> cloth >> type;
            
            map<string, int>::iterator itr = dress.find(type);
            
            if(itr == dress.end()) dress.insert({type, 2});
            else itr->second++;
        }
        
        int cases = 1;
        
        for(map<string, int>::iterator itr = dress.begin(); itr != dress.end(); itr++)
            cases *= (itr->second);
        
        cout << cases - 1 << '\n';
    }
}

int main()
{
    Solve();

    return 0;
}