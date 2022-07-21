#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solution(vector<int> scoville, int K) 
{
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.empty() == false)
	{
		int sc1 = pq.top();
		pq.pop();

		if (sc1 < K)
		{
			if (pq.empty() == true)
			{
				answer = -1;
				break;
			}

			pq.push(sc1 + pq.top() * 2);
			pq.pop();
			answer++;
		}

		else
		{
			break;
		}
	}

	return answer;
}