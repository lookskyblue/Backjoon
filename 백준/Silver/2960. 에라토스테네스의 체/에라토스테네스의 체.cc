#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, remove_count;
vector<int> v;

bool IsPrime(int val)
{
	for (int i = 2; i < val; i++)
		if (val % i == 0) // 소수가 아님.
			return false;

	return true;
}

void Solve()
{
	for (int i = 2; i <= N; i++)
		v.push_back(i);

	sort(v.begin(), v.end());

	while (v.size() != 0)
	{
		int delete_idx = 0;
		int prime = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (IsPrime(v[i]) == true)
			{
				delete_idx = i;
				prime = v[i];
				break;
			}
		}

		v.erase(v.begin() + delete_idx);

		if (++remove_count == K)
		{
			cout << prime;
			return;
		}

		// 구한 소수의 배수 삭제.
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] % prime == 0)
			{
				if (++remove_count == K)
				{
					cout << v[i];
					return;
				}

				v.erase(v.begin() + i);
				i--;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	Solve();
}
