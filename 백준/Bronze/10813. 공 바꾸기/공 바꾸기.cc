#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void Solve()
{
	int N, M;

	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		v[i] = i + 1;
	}

	for (int i = 0; i < M; i++)
	{
		int J, K;

		cin >> J >> K;

		J--;
		K--;

		int temp = v[J];
		v[J] = v[K];
		v[K] = temp;
	}

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}