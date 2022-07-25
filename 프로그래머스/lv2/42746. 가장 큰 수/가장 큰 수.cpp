#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
    string as = to_string(a);
    string bs = to_string(b);

    return as + bs > bs + as;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers.at(0) == 0) return "0";
        answer += to_string(numbers[i]);
    }

    return answer;
}