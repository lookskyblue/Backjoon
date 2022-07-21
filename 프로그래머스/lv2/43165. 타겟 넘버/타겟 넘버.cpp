#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int answer;

void DFS(vector<int> numbers, int sum, int idx, int target)
{
	if (numbers.size() - 1 == idx)
	{
		if ((sum + numbers[idx]) == target)	answer++;
		if ((sum - numbers[idx]) == target)	answer++;
		return;
	}

	DFS(numbers, sum + numbers[idx], idx + 1, target);
	DFS(numbers, sum - numbers[idx], idx + 1, target);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, 0, 0, target);
	return answer;
}