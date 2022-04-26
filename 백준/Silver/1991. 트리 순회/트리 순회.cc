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

		Node* node = new Node(now_data);
		Node* left_node = new Node(left_data);
		Node* right_node = new Node(right_data);

		if (tree.nodes[left_data - 'A'] == nullptr)
			tree.nodes[left_data - 'A'] = left_node;
		else
			left_node = tree.nodes[left_data - 'A'];

		if (tree.nodes[right_data - 'A'] == nullptr)
			tree.nodes[right_data - 'A'] = right_node;
		else
			right_node = tree.nodes[right_data - 'A'];

		if (now_data == 'A' && tree.GetRoot() == nullptr)
			tree.SetRoot(node);

		if (tree.nodes[now_data - 'A'] == nullptr)
			tree.nodes[now_data - 'A'] = node;
		
		else
			node = tree.nodes[now_data - 'A'];

		if (left_data == '.')
			node->SetLeft(nullptr);

		else
			node->SetLeft(left_node);

		if (right_data == '.')
			node->SetRight(nullptr);

		else
			node->SetRight(right_node);
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