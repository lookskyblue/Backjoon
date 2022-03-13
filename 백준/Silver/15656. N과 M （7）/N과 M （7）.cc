#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
vector<int> v;
int arr[8];

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

void DFS(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; i++)
	{
		arr[cnt] = v[i];
		DFS(cnt + 1);
	}
}

int main()
{
	Input();
	DFS(0);
}
