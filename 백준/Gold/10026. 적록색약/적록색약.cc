#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

char map[100][100];
char copy_map[100][100];

void SearchSection(int i, int j, int n, char from, char to)
{
    if (i < 0 || i == n || j < 0 || j == n) return;
    if (map[i][j] != from) return;
    
    map[i][j] = to;

    SearchSection(i + 1, j, n, from, to);
    SearchSection(i - 1, j, n, from, to);
    SearchSection(i, j + 1, n, from, to);
    SearchSection(i, j - 1, n, from, to);
}

int ChangeAlpha(int n, char from, char to)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == from)
            {
                SearchSection(i, j, n, from, to);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n, non_rg = 0, rg = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++)
        {
            map[i][j] = line[j];
        }
    }

    copy(&map[0][0], &map[0][0] + 10000, &copy_map[0][0]);

    cout << ChangeAlpha(n, 'R', 0) + ChangeAlpha(n, 'G', 0) + ChangeAlpha(n, 'B', 0) << " ";
    copy(&copy_map[0][0], &copy_map[0][0] + 10000, &map[0][0]);

    ChangeAlpha(n, 'G', 'R');
    cout << ChangeAlpha(n, 'R', 0) + ChangeAlpha(n, 'B', 0);;

    return 0;
} 
