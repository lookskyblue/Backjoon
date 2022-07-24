#include<map> 
#include<set> 
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> answer;

void Solve(vector<int>& array, vector<int>& command)
{
    vector<int> tmp(array.begin() + command[0] - 1, array.begin() + command[1]);
    int k = command[2] - 1;

    sort(tmp.begin(), tmp.end());

    answer.push_back(tmp[k]);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

    for (int i = 0; i < commands.size(); i++)
    {
        Solve(array, commands[i]);
    }

    return answer;
}