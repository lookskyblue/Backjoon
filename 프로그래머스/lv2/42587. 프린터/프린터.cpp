#include <string>
#include <vector>

using namespace std;
int solution(vector<int> priorities, int location) {
    
    vector<pair<int, int>> job_queue;

    for (int i = 0; i < priorities.size(); i++)
    {
        pair<int, int> p = pair<int, int>(priorities[i], i);

        job_queue.push_back(p);
    }

    int answer = 0;
    int print_count = 0;

    while (job_queue.empty() == false)
    {
        pair<int, int> job = *job_queue.begin();

        bool is_push_back = false;

        for (int i = 1; i < job_queue.size(); i++)
        {
            if (job.first < job_queue[i].first)
            {
                job_queue.erase(job_queue.begin());
                job_queue.push_back(job);
                is_push_back = true;

                break;
            }
        }

        if (is_push_back == false)
        {
            int pr_location = (*job_queue.begin()).second;

            job_queue.erase(job_queue.begin());
            print_count++;

            if (pr_location == location)
            {
                answer = print_count;
                break;
            }
        }
    }

    return answer;
}
