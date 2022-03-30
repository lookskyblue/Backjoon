#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

int priory_queue[100002];
int queue_size = 0;

void Push(int x)
{
	int idx = ++queue_size;

	while (idx != 1 && priory_queue[idx / 2] > x)
	{
		priory_queue[idx] = priory_queue[idx / 2];
		idx /= 2;
	}

	priory_queue[idx] = x;
}

int Pop()
{
	if (queue_size == 0) return 0;

	int erased_item = priory_queue[1];
	int last_item = priory_queue[queue_size--];
	int par_idx = 1;
	int chi_idx = 2;

	while (chi_idx <= queue_size)
	{
		if (chi_idx < queue_size && priory_queue[par_idx * 2] > priory_queue[par_idx * 2 + 1])
			chi_idx++;

		if (last_item <= priory_queue[chi_idx]) break;

		priory_queue[par_idx] = priory_queue[chi_idx];
		par_idx = chi_idx;
		chi_idx *= 2;
	}

	priory_queue[par_idx] = last_item;
	return erased_item;
}

void Solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;

		if (value == 0) cout << Pop() << '\n';
		else Push(value);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}