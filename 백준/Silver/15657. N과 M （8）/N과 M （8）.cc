#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
vector<int> v;
vector<int> ans;

void Input()
{
	cin >> N >> M; 
	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());
}

void DFS(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << " ";
		cout << '\n';

		return;
	}

	for (int i = idx; i < N; i++)
	{
		ans.push_back(v[i]);
		DFS(i, cnt + 1);
		ans.pop_back();
	}
}

int main()
{
	Input();
	DFS(0, 0);
}
