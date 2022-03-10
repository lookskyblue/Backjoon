#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];

void SetRect(int x1, int y1, int x2, int y2, int m)
{
    y1 = m - y1;
    y2 = m - y2;

    for (int i = y2; i < y1; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            map[i][j] = 1;
        }
    }
}

int SearchSection(int i, int j, int width, int height)
{
    if (i < 0 || i == height || j < 0 || j == width) return 0;
    if (map[i][j] != 0) return 0;

    map[i][j] = 1;

    return 1 +
        SearchSection(i + 1, j, width, height) +
        SearchSection(i - 1, j, width, height) +
        SearchSection(i, j + 1, width, height) +
        SearchSection(i, j - 1, width, height);
}

int main()
{
    vector<int> v;
    int m, n, k; // m: 세로, n: 가로 
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        SetRect(x1, y1, x2, y2, m);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0)
                v.push_back(SearchSection(i, j, n, m));
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    
    for(auto item : v)
    {
        cout << item << " ";
    }

    return 0;
} 
