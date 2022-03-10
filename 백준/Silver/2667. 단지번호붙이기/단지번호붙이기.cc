#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];

int CheckHouse(int i, int j, int n)
{
    if (i < 0 || i == n || j < 0 || j == n) return 0;
    if (map[i][j] == 0) return 0;
    
    map[i][j] = 0;

    return 1 + CheckHouse(i + 1, j, n) + CheckHouse(i - 1, j, n) + CheckHouse(i, j + 1, n) + CheckHouse(i, j - 1, n);
}

int main()
{
    vector<int> house_count_list;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++)
        {
            map[i][j] = line[j] - 48; // string으로 받았기에 해당 문자의 아스키 만큼 빼주기 
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j])
                house_count_list.push_back(CheckHouse(i, j, n));
        }
    }

    sort(house_count_list.begin(), house_count_list.end());

    int v_size = house_count_list.size();
    
    cout << v_size << endl;

    for (int i = 0; i < v_size; i++)
    {
        cout << house_count_list[i] << endl;
    }

    return 0;
} 
