#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void CntEachNum(string str)
{
	int arr[10] = { 0, };

	for (int i = 0; i < (int)str.size(); i++)
	{
		arr[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	string str = to_string(a * b * c);

	CntEachNum(str);

	return 0;
}