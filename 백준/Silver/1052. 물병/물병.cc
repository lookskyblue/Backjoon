#include <bitset>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
vector<int> a;

void makeBit(int num)
{
	while (num != 0)
	{
		a.push_back(num % 2);
		num = num / 2;
	}
}

int main() {
	
	int n, k, i=0;
	cin >> n >> k;
	
	// 1. n을 비트로 환산.

	// 2. bit에 1의 수 count.

	while (1)
	{

		int count = 0;
		
		 
		a.clear();
		makeBit(n + i);
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == 1)
				count++;
		}

		if (count <= k)
			break;

		// 1더하고, 환산하고
		i++;
	}

	cout << i;

	return 0;
}