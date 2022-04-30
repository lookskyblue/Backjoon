#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int GetDecompose(int n)
{
	int sum = 0;

	sum += n;

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

void Input()
{
	int n;
	cin >> n;

	for(int count = 1; count <= 1000000; count++)
	{
		int value = GetDecompose(count);

		if (value == n)
		{
			cout << count;
			return;
		}
	}

	cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}