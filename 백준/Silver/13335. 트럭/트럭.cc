#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, w, l;
vector<pair<int, int>> bridge_v;
queue<pair<int, int>> truck_q;

void Input() 
{ 
	cin >> n >> w >> l; 
	
	for (int i = 0; i < n; i++)
	{
		int truck_weight;
		cin >> truck_weight;
		truck_q.push({ w,truck_weight });
	}
}

void Solve()
{
	int time = 0;
	int now_bridge_weight = 0;

	while (bridge_v.size() != 0 || truck_q.size() != 0)
	{
		if (bridge_v.size() != 0)
		{
			time++;
			int size = bridge_v.size();

			for (int i = 0; i < size; i++)
				bridge_v[i].first--;

			for (int i = 0; i < size; i++)
			{
				if (bridge_v[0].first == 0)
				{
					now_bridge_weight -= bridge_v[0].second;
					bridge_v.erase(bridge_v.begin());
				}
			}
		}

		if (bridge_v.size() < w)
		{
			if (truck_q.size() != 0)
			{
				if ((now_bridge_weight + truck_q.front().second) <= l)
				{
					now_bridge_weight += truck_q.front().second;
					bridge_v.push_back({ truck_q.front().first, truck_q.front().second });
					truck_q.pop();
				}
			}
		}
	}

	cout << time + 1;
}

int main()
{
	Input();
	Solve();

	return 0;
} 