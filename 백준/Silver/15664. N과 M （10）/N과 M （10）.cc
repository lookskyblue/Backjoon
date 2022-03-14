#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[8];
int selected[8];

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
}

void DFS(int idx, int cnt)
{
	int before_val = 0;

	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (before_val == arr[i]) continue;

		selected[cnt] = arr[i];
		before_val = arr[i];

		DFS(i + 1, cnt + 1);
	}
}

int main()
{
	Input();
	DFS(0, 0);

	return 0;
}