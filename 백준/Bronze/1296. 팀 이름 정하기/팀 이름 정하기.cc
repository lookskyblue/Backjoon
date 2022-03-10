#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int GetLoveCount(string name)
{
    int love_count[4] = { 0 };

    for (int i = 0; i < name.length(); i++)
    {
        if ('L' == name[i]) love_count[0]++;
        else if ('O' == name[i]) love_count[1]++;
        else if ('V' == name[i]) love_count[2]++;
        else if ('E' == name[i]) love_count[3]++;
    }

	int score = ((love_count[0] + love_count[1]) *
		(love_count[0] + love_count[2]) *
		(love_count[0] + love_count[3]) *
		(love_count[1] + love_count[2]) *
		(love_count[1] + love_count[3]) *
		(love_count[2] + love_count[3])) % 100;

    return score;
}

int main()
{
    string my_name;
    int n;

    cin >> my_name;
    cin >> n;

    string* others = new string[n];

    for (int i = 0; i < n; i++)
        cin >> others[i];

    sort(others, others + n);

    int best = 0;
    int best_idx = 0;

    for (int i = 0; i < n; i++)
    {
        int score = GetLoveCount(my_name + others[i]);

        if (best < score)
        {
            best = score;
            best_idx = i;
        }
    }

    cout << others[best_idx];

    return 0;
}