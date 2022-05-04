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

long long X, Y;
int ans = 1000000001;

void Solve() 
{
	//Z = (((double)Y / X) * 100);
	//Z = int(((double)Y / X) * 100);
	int Z = (100 * Y) / X;

	int start = 1;
	int mid = 0;
	int end = 1000000000;
	
	//cout << "((double)Y / X) * 100 : " << ((double)Y / X) * 100 << "\n";
	//cout << "(int)(((double)Y / X) * 100) : " << (int)(((double)Y / X) * 100) << "\n";
	//double tmp_z = ((double)Y / X) * 100;
	//cout << "tmp_z: " << tmp_z << "\n";
	//cout << "tmp_z: " << (int)(floor(tmp_z)) << "\n";
	
	//cout << "Z: " << Z << "\n";

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (Z < (100*(Y + mid)) / (X + mid))
		//if ((((((double)(Y + mid)) / (X + mid)) * 100)) - Z > (double)1)
		//if (abs(((((double)Y+mid) / (X+mid)) * 100) - Z) >= double(1))
		{
			ans = min(ans, mid);
			end = mid - 1;
		}

		else start = mid + 1;
	}

	cout << ((ans == 1000000001) ? -1 : ans);
}

void Input()
{
	cin >> X >> Y;

	Solve();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}