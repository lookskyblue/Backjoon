#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>

using namespace std;

class Node {
private:
	char data;
	Node* left;
	Node* right;

public:
	Node(char data, Node* left = nullptr, Node* right = nullptr)
		: data(data), left(left), right(right){}

	void SetLeft(Node* node) { left = node; }
	void SetRight(Node* node) { right = node; }
	void SetData(char d) { data = d; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	char GetData() { return data; }
};

class Tree {
private:
	Node* root;

public:
	Node* nodes[26];
	Tree()
		: root(nullptr){
		for (int i = 0; i < 26; i++)
			nodes[i] = nullptr;
	}

	Node* GetRoot() { return root; }
	void SetRoot(Node* node) { root = node; }
	void PreOrder(Node* node) 
	{
		if (node == nullptr) return;

		cout << node->GetData();
		PreOrder(node->GetLeft());
		PreOrder(node->GetRight());
	}

	void InOrder(Node* node)
	{
		if (node == nullptr) return;

		InOrder(node->GetLeft());
		cout << node->GetData();
		InOrder(node->GetRight());
	}

	void PostOrder(Node* node)
	{
		if (node == nullptr) return;

		PostOrder(node->GetLeft());
		PostOrder(node->GetRight());
		cout << node->GetData();
	}
};

void Input()
{
	Tree tree = Tree();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char now_data, left_data, right_data;
		cin >> now_data >> left_data >> right_data;

		if (tree.nodes[now_data - 'A'] == nullptr)
			tree.nodes[now_data - 'A'] = new Node(now_data);

		if (tree.nodes[left_data - 'A'] == nullptr)
			tree.nodes[left_data - 'A'] = new Node(left_data);

		if (tree.nodes[right_data - 'A'] == nullptr)
			tree.nodes[right_data - 'A'] = new Node(right_data);

		if (now_data == 'A' && tree.GetRoot() == nullptr)
			tree.SetRoot(tree.nodes[now_data - 'A']);

		tree.nodes[now_data - 'A']->SetData(now_data);

		if (left_data == '.')
			tree.nodes[now_data - 'A']->SetLeft(nullptr);
		else
			tree.nodes[now_data - 'A']->SetLeft(tree.nodes[left_data - 'A']);

		if (right_data == '.')
			tree.nodes[now_data - 'A']->SetRight(nullptr);
		else
			tree.nodes[now_data - 'A']->SetRight(tree.nodes[right_data - 'A']);


	}

	tree.PreOrder(tree.GetRoot());
	cout << '\n';
	tree.InOrder(tree.GetRoot());
	cout << '\n';
	tree.PostOrder(tree.GetRoot());
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	return 0;
}