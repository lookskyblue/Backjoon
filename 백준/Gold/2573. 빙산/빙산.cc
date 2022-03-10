#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int map[300][300];
int cp_map[300][300];

void SearchSection(int i, int j, int n, int m)
{
    if (i < 0 || i == n || j < 0 || j == m) return;
    if (map[i][j] <= 0) return;
    
    map[i][j] = 0;

    SearchSection(i + 1, j, n, m);
    SearchSection(i - 1, j, n, m);
    SearchSection(i, j + 1, n, m);
    SearchSection(i, j - 1, n, m);
}

int Melt2(int i, int j, int n, int m)
{
    if (i < 0 || i == n || j < 0 || j == m) return 0;
    if (map[i][j] == 0) return 1;
    if (map[i][j] < 0) return 0;
    
    return 0;
}

void Melt(int i, int j, int n, int m)
{
    int zero_count = Melt2(i+1, j, n, m) + Melt2(i-1, j, n, m) + Melt2(i, j+1, n, m) + Melt2(i, j-1, n, m);

    map[i][j] -= zero_count;

    if (map[i][j] <= 0) map[i][j] = -1;
}

void ChangeMinusToZero(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] < 0) map[i][j] = 0;
        }
    }
}

int main()
{
    int n, m; // n 세로 m 가로
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    copy(&map[0][0], &map[0][0] + 90000, &cp_map[0][0]);

    int i = 0;

    while(1)
    {
        i++;
        int lump = 0;
        
        copy(&cp_map[0][0], &cp_map[0][0] + 90000, &map[0][0]);
        ChangeMinusToZero(n, m);

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (map[j][k] > 0)
                    Melt(j, k, n, m);
            }
        }

        //cout << endl;
        /*for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cout << map[j][k] << " ";
            }
            cout << endl;
        }*/

        copy(&map[0][0], &map[0][0] + 90000, &cp_map[0][0]);

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (map[j][k] > 0)
                {
                    SearchSection(j, k, n, m);
                    lump++;
                    
                    if (lump >= 2)
                    {
                        cout << i;
                        return 0;
                    }
                }
            }
        } // 만약 덩어리가 하나도 없다면.. 다 녹은거

        if (lump == 0)
        {
            cout << 0;
            return 0;
        }
    }

    return 0;
} 
