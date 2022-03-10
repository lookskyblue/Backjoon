#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    const int MAX = 11;
    int n = 0;
    cin >> n;

    int stature[MAX];
    bool fixed[MAX] = { false };

    for (int i = 0; i < n; i++)
    {
        stature[i] = i + 1;
    }

    for(int i = 0; i < n; i++)
    {
        int taller_count;
        cin >> taller_count;

        for (int j = 0; j < n; j++)
        {
            if (stature[j] == i + 1) // 1, 2, 3, 4 하나씩 찾았을 때.
            {
                for (int k = j-1; k >= 0; k--) // 앞으로 찾기
                {
                    if (stature[k] > stature[j])
                        taller_count--;
                }

                for (int h = j + 1; h < n; h++) // 뒤로 찾기
                {
                    if (taller_count == 0)
                        break;

                    if (fixed[stature[h]-1] == true)
                        continue;


                    if (stature[h] > stature[j])
                    {
                        int tmp = stature[h];
                        stature[h] = stature[j];
                        stature[j] = tmp;

                        fixed[i] = true;
                        taller_count--;
                        j = h;
                    }
                }

                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << stature[i] << " ";
        
    return 0;
}