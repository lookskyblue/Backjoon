#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while (progresses.empty() == false)
    {
        for (int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];

        int erase_count = 0;

        while (progresses.empty() == false && *(progresses.begin()) >= 100)
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());

            erase_count++;
        }

        if (erase_count != 0)
            answer.push_back(erase_count);
    }

    return answer;
}