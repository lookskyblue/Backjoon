#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>;
#include <map>;

using namespace std;

vector<pair<int, int>> v;
stack<pair<int, int>> s;
int sight_info[80001];
long long ans;

void Input()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back({ x, i });
	}

	for (int i = v.size() - 1; i > -1; i--)
	{
		int now_sight = 0;

		while (s.empty() == false)
		{
			if (s.top().first >= v[i].first) // 앞에 빌딩 안보임.
			{
				s.push(v[i]);
				break;
			}

			else // 앞에 빌딩이 보임
			{
				int front_idx = s.top().second;
				now_sight += (sight_info[front_idx] + 1);
				s.pop();
			}
		}

		if (s.empty() == true)
			s.push(v[i]);

		sight_info[v[i].second] = now_sight;
		ans += now_sight;
	}

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}
