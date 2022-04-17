#include <iostream>
#include <map>

using namespace std;

map<long long, int> card_map;

void Input()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;
        
        map<long long, int>::iterator itr = card_map.find(value);
        
        if(itr == card_map.end())
            card_map.insert({value, 1});
        
        else
            itr->second++;
    }
    
    long long max_num = 0;
    int max_count = 0;
    map<long long, int>::iterator itr;
    
    for(itr = card_map.begin(); itr != card_map.end(); itr++)
    {
        if(max_count < itr->second)
        {
            max_count = itr->second;
            max_num = itr->first;
        }
    }
    
    cout << max_num;
}

int main()
{
    Input();

    return 0;
}