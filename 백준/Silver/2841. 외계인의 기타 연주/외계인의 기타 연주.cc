#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

stack<int> s[6];
int answer;

void Input()
{
	int N, P;
	cin >> N >> P;

	for (int i = 0; i < N; i++)
	{
		int idx, plat;
		cin >> idx >> plat;

		idx--;

		if (s[idx].empty() == true) // 스택이 비었으면 
		{
			s[idx].push(plat);
			answer++;
		}

		else // 스택이 비어있지 않다면
		{
			if (s[idx].top() < plat) // 최신 플랫이 더 높다면 
			{
				s[idx].push(plat);
				answer++;
			}

			else if (s[idx].top() > plat) // 최신 플랫이 더 낮다면
			{
				while (s[idx].empty() == false && s[idx].top() != plat)
				{
					if (s[idx].top() > plat)
					{
						s[idx].pop();
						answer++;

						if (s[idx].empty() == true)
						{
							s[idx].push(plat);
							answer++;
							break;
						}
					}

					else
					{
						s[idx].push(plat);
						answer++;
						break;
					}
				}
			}
		}
	}

	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();

	return 0;
}