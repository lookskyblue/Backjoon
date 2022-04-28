#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

class Node
{
	int data;
	Node* parent;

public:
	Node(int value)
		: data(value), parent(nullptr)
	{}

	int GetData() { return data; }
	void SetParent(Node* n) { parent = n; }
	Node* GetParent() { return parent; }

};

int N;
Node* nodes[10001];
set<int> history_a;

void DFS(int start, set<int>* history)
{
	history->insert(nodes[start]->GetData());

	if (nodes[start]->GetParent() == nullptr) return;
	DFS(nodes[start]->GetParent()->GetData(), history);
}

void DFS(int start)
{
	if (history_a.find(start) != history_a.end())
	{
		cout << *history_a.find(start) << '\n';
		return;
	}

	if (nodes[start]->GetParent() == nullptr) return;
	DFS(nodes[start]->GetParent()->GetData());
}

void Solve(int a, int b)
{
	DFS(a, &history_a);
	DFS(b);

	/*for (int i = 0; i < history_a.size(); i++)
	{
		cout << history_a[i] << " ";
	}

	cout << '\n';*/
}

void Input()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;

			Node* node_a;
			Node* node_b;

			if (nodes[a] == nullptr)
			{
				node_a = new Node(a);
				nodes[a] = node_a;
			}
			else
				node_a = nodes[a];

			if (nodes[b] == nullptr)
			{
				node_b = new Node(b);
				nodes[b] = node_b;
			}
			else
				node_b = nodes[b];

			node_b->SetParent(node_a);
		}

		int from_a, from_b;
		cin >> from_a >> from_b;

		Solve(from_a, from_b);
		history_a.clear();

		for (int i = 1; i <= N; i++)
		{
			free(nodes[i]);
			nodes[i] = nullptr;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}