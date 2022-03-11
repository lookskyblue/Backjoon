#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> v;
vector<int> sansool_v;
vector<pair<int, int>> p;
int arr[8001];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);

		arr[val+4000]++;
	}
}

void Sansool()
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	int res = round((float)sum / N);
	res = res == 0 ? 0 : res;
	cout << round(res) << endl;
}

void MiddleValue()
{
	int idx = v.size() / 2;
	cout << v[idx] << endl;
}

void MinMax()
{
	cout << v[v.size() - 1] - v[0] << endl;
}

void ChoiBinValue()
{
	int max_value = 0;
	for (int i = 0; i < 8001; i++)
	{
		max_value = max(max_value, arr[i]);
	}

	for (int i = 0; i < 8001; i++)
	{
		if (arr[i] == max_value) // 인덱스 담아
		{
			sansool_v.push_back(i - 4000);
		}
	}

	sort(sansool_v.begin(), sansool_v.end());

	int res = sansool_v.size() == 1 ? sansool_v[0] : sansool_v[1];
	cout << res << endl;
}

void Solve()
{
	sort(v.begin(), v.end());

	Sansool();
	MiddleValue();
	ChoiBinValue(); // 어캐 조지누
	MinMax();
}

int main()
{
	Input();
	Solve();
}
