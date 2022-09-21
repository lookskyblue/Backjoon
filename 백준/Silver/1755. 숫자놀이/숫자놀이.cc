#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

vector<string> english
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

struct cmp
{
	bool operator()(pair<string, int> a, pair<string, int> b)
	{
		return a.first > b.first;
	}
};

void Solve()
{
	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		int value = i;

		string word;
		int a, b;

		b = value % 10;
		value /= 10;

		if (value != 0)
		{
			word = english[value];
			word += " " + english[b];
		}

		else
		{
			word = english[b];
		}

		pq.push({ word, i });
	}

	int cnt = 0;

	while (pq.empty() == false)
	{
		 pair<string, int> p = pq.top();

		 cout << p.second << " ";

		 if (++cnt % 10 == 0)
		 {
			 cout << '\n';
		 }

		 pq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}