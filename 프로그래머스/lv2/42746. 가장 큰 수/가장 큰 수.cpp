#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool cmp(string &a, string &b)
{
    return (a + b > b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(0) == "0") return "0";
        answer += v[i];
    }

    return answer;
}