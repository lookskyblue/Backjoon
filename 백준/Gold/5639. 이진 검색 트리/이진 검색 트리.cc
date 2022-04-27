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
	int data;
	Node* ln;
	Node* rn;

public:
	Node()
		: ln(nullptr), rn(nullptr){}

	void SetData(int value) { data = value; }
	int GetData() { return data; }
	void SetLeft(Node* node) { ln = node; }
	void SetRight(Node* node) { rn = node; }
	Node* GetLeft() { return ln; }
	Node* GetRight() { return rn; }
};

class Tree
{
	Node* root;
public:
	Tree()
		: root(nullptr) {}

	void SetRoot(Node* node) { root = node; }
	Node* GetRoot() { return root; }

	void InsertNode(Node* now_node, Node* new_node)
	{
		//cout << "now_node data: " << now_node->GetData() << ", new_node data: " << new_node->GetData();

		if (now_node->GetData() > new_node->GetData())
		{
			if (now_node->GetLeft() == nullptr)
			{
				//cout << "1" << '\n';
				now_node->SetLeft(new_node);
			}
			else
			{
				//cout << "2" << '\n';
				InsertNode(now_node->GetLeft(), new_node);
			}
		}
		else
		{
			if (now_node->GetRight() == nullptr)
			{
				// cout << "3" << '\n';
				now_node->SetRight(new_node);
			}
			else
			{
				// cout << "4" << '\n';
				InsertNode(now_node->GetRight(), new_node);
			}
		}
	}

	void PostOrder(Node* now_node)
	{
		if (now_node == nullptr) return;

		PostOrder(now_node->GetLeft());
		PostOrder(now_node->GetRight());
		cout << now_node->GetData() << '\n';
	}
};

void Input3()
{
	Tree tree = Tree();
	string key;

	while(getline(cin, key))
	{
		int key_data = stoi(key);

		Node* node = new Node();
		node->SetData(key_data);

		if (tree.GetRoot() == nullptr)
		{
			//cout << "루트 설정";
			tree.SetRoot(node);
			//cout << "루트 설정 후 데이터: " << tree.GetRoot()->GetData() << '\n';
		}
		else
		{
			//cout << "before insert root data: " << tree.GetRoot()->GetData() << ", new data: " << node->GetData() << '\n';
			tree.InsertNode(tree.GetRoot(), node);
			//cout << "after insert root data: " << tree.GetRoot()->GetData() << ", new data: " << node->GetData() << '\n';
		}
	}

	tree.PostOrder(tree.GetRoot());
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input3();

	return 0;
}