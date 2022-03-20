#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> gear[4];
bool gear_selected[4];
int K;
// 2, 6

void Input()
{
    for(int i = 0; i < 4; i++)
    {
        string gear_state;
        cin >> gear_state;
        
        for(int j = 0; j < 8; j++)
        {
            gear[i].push_back(gear_state[j] - '0');
        }
    }
    
    cin >> K;
}

void DFS(int main_gear_num, int effected_gear_num, int gear_dir, int gear_left, int gear_right)
{
    if(effected_gear_num == -1 || effected_gear_num == 4) return;
    if(gear_selected[effected_gear_num] == true) return;
    if(main_gear_num < effected_gear_num)
    {
        if(gear_right == gear[effected_gear_num][6]) return;
    }
    
    else if(effected_gear_num < main_gear_num)
    {
        if(gear[effected_gear_num][2] == gear_left) return;
    }
    
    gear_selected[effected_gear_num] = true;
    
    DFS(main_gear_num, effected_gear_num - 1, gear_dir * -1, gear[effected_gear_num][6], gear[effected_gear_num][2]);
    DFS(main_gear_num, effected_gear_num + 1, gear_dir * -1, gear[effected_gear_num][6], gear[effected_gear_num][2]);
    
    if(gear_dir == 1) // 시계
    {
        int gear_value = gear[effected_gear_num][7];
        gear[effected_gear_num].erase(gear[effected_gear_num].begin() + 7);
        gear[effected_gear_num].insert(gear[effected_gear_num].begin(), gear_value);
    }
    
    else // 반시계
    {
        int gear_value = gear[effected_gear_num][0];
        gear[effected_gear_num].erase(gear[effected_gear_num].begin());
        gear[effected_gear_num].insert(gear[effected_gear_num].end(), gear_value);
    }
    
    gear_selected[effected_gear_num] = false;
}

void Solve()
{
    int gear_num, gear_dir;
    
    for(int i = 0; i < K; i++)
    {
        cin >> gear_num >> gear_dir;
        gear_num--;
        
        DFS(gear_num, gear_num, gear_dir, gear[gear_num][6], gear[gear_num][2]);
    }
    
    // 점수 출력
    int score = 0;
    if(gear[0][0] == 1) score += 1;
    if(gear[1][0] == 1) score += 2;
    if(gear[2][0] == 1) score += 4;
    if(gear[3][0] == 1) score += 8;
    
    cout << score;
    
    // 기어 값 출력
    
    // for(int i = 0; i < 4; i++)
    // {
    //     for(int j = 0; j < 8; j++)
    //     {
    //         cout << gear[i][j];
    //     }
    //     cout << '\n';
    // }
}

int main()
{
    Input();
    Solve();

    return 0;
}