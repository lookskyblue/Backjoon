#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[7];
int selected[7];

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
}

void DFS(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
			cout << selected[i] << " ";
		cout << '\n';

		return;
	}

	int before_value = 0;

	for (int i = 0; i < N; i++)
	{
		if (before_value == arr[i]) continue;

		selected[cnt] = arr[i];
		before_value = arr[i];

		DFS(cnt + 1);
	}
}

int main()
{
	Input();
	DFS(0);

	return 0;
}