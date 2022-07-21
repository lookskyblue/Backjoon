#include <string>
#include <vector>

using namespace std;

int answer;

void DFS(vector<int> &numbers, int sum, int now_idx, int &target)
{
    if (now_idx == numbers.size())
    {
        if (sum == target) answer++;
        return;
    }

    DFS(numbers, sum + numbers[now_idx], now_idx+1, target);
    DFS(numbers, sum - numbers[now_idx], now_idx+1, target);
}

int solution(vector<int> numbers, int target) {

    answer = 0;

    int sum = 0;
    int now_idx = 0;

    DFS(numbers, sum, now_idx, target);

    return answer;
}