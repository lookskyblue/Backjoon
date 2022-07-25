#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int parent[100];

int getParent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findUnion(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b) return true;
	else return false;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	vector< pair<int, pair<int, int>>> edge;

	for (int i = 0; i < costs.size(); i++)
	{
		int weight = costs[i][2];
		int a = costs[i][0];
		int b = costs[i][1];

		edge.push_back({ weight, {a, b} });
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++)
	{
		int weight = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (findUnion(a, b) == false)
		{
			unionParent(a, b);
			answer += weight;
		}
	}

	return answer;
}