#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;

int GetProcessedComputer(int a, int b)
{
	int sum = 1;
	
	for (int i = 0; i < b; i++)
	{
		sum *= a;
		sum %= 10;
	}

	return (sum == 0 ? 10 : sum);
}

void Solve()
{
	while (T--)
	{
		int a, b;

		cin >> a >> b;
		cout << GetProcessedComputer(a, b) << '\n';
	}
}

int main()
{
	cin >> T;
	Solve();
	
	return 0;
}