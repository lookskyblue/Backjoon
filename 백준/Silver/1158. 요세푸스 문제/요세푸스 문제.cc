#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N, K;

void Solve()
{
	vector<int> v;
	cin >> N >> K;
	K--;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	cout << "<";
	cout << v[K];
	v.erase(v.begin() + K);

	int idx = K;

	while (v.empty() == false)
	{
		idx = (idx + K) % v.size();
		cout << ", ";
		cout << v[idx];
		v.erase(v.begin() + idx);
	}

	cout << ">";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}