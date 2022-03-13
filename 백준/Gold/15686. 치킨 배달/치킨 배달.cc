#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M;
int ans = 999999999;
vector<pair<int, int>> chicken_pos, house_pos, selected_chicken;

int GetDist()
{
    int dist_sum = 0;
    
    for(int i = 0; i < house_pos.size(); i ++)
    {
        int min_dist = 999999999;
        
        for(int j = 0; j < selected_chicken.size(); j++)
        {
            int tmp = (abs(house_pos[i].first - selected_chicken[j].first) + abs(house_pos[i].second - selected_chicken[j].second));
            min_dist = min(min_dist, tmp);
        }
        
        dist_sum += min_dist;
    }
    
    return dist_sum;
}

void SelectChicken(int idx, int count)
{
    if(count == M)
    {
        ans = min(ans, GetDist());
        return;
    }
    
    for(int i = idx; i < chicken_pos.size(); i++)
    {
        selected_chicken.push_back(chicken_pos[i]);
        SelectChicken(i + 1, count+1);
        selected_chicken.pop_back();
    }
}

void Solve()
{
    SelectChicken(0, 0);
    cout << ans;
}

void Input()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int val;
            cin >> val;
            
            if(val == 1) house_pos.push_back({i, j});
            if(val == 2) chicken_pos.push_back({i, j});
        }
    }
}

int main()
{
    Input();
    Solve();

    return 0;
}