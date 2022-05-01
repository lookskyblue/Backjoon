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

int k;

int GetRootIdx(map<int, vector<int>>& nv, set<int>& v_node)
{
	for (map<int, vector<int>>::iterator itr = nv.begin(); itr != nv.end(); itr++)
		if (v_node.find(itr->first) == v_node.end())
			return itr->first;
}

//void GetEdgeVertex(int idx)
//{
//	nv_visit[idx] = true;
//
//	all_edge += nv[idx].size();
//	all_vertex++;
//
//	for (set<int>::iterator itr = nv[idx].begin(); itr != nv[idx].end(); itr++)
//	{
//		if (nv_visit[*itr] == false)
//			GetEdgeVertex(*itr);
//	}
//}

bool IsDoubleVisit(int idx, map<int, bool>& nv_visit, map<int, vector<int>>& nv)
{
	/*if (nv_visit[idx] == true)
		return true;

	nv_visit[idx] = true;

	for (int i = 0; i < nv[idx].size(); i++)
	{
		if (IsDoubleVisit(nv[idx][i], nv_visit, nv) == true)
			return true;
	}

	return false;*/

	map<int, int> ck_map;

	for (auto t : nv)
	{
		for (auto el : t.second)
			ck_map[el] = 1;
	}

	int root = 0;

	for (auto t : nv)
	{
		if (ck_map[t.first] == 0)
			root = t.first;
	}

	ck_map.clear();
	ck_map[root] = 1;

	queue<int> q;
	q.push(root);

	//nv_visit[idx] = true;

	while (q.empty() == false)
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < nv[x].size(); i++)
		{
			if (ck_map[nv[x][i]] == 1) return true;
			ck_map[nv[x][i]] = 1;
			q.push(nv[x][i]);
		}
	}

	//for (map<int, bool>::iterator itr = nv_visit.begin(); itr != nv_visit.end(); itr++)
	//	if (itr->second == false) return true;

	for (auto t : nv)
	{
		for (auto el : t.second)
		{
			if (ck_map[el] == 0 || ck_map[t.first] == 0) return true;
			//if (nv_visit.find(el) == nv_visit.end()) return true;
			//else if (nv_visit.find(el)->second == false) return true;
		}
	}

	return false;
}

bool IsAllVisit(map<int, bool>& nv_visit)
{
	for (map<int, bool>::iterator itr = nv_visit.begin(); itr != nv_visit.end(); itr++)
		if (itr->second == false) return false;

	return true;
}

void CheckTree(int edge_cnt, set<int>& v_node, map<int, vector<int>>& nv, map<int, bool>& nv_visit)
{
	cout << "Case " << ++k << " is ";

	/*if (edge_cnt + 1 != nv_visit.size())
	{
		cout << "not a tree." << '\n';
		return;
	}*/

	// int root_idx = GetRootIdx(nv, v_node);
	//GetEdgeVertex(root_idx);

	bool is_double_visit = IsDoubleVisit(-1, nv_visit, nv);
	//bool is_all_visit = IsAllVisit(nv_visit);

	if (is_double_visit == true)
	{
		cout << "not a tree." << '\n';
		return;
	}

	/*if (is_all_visit == false)
	{
		cout << "not a tree." << '\n';
		return;
	}*/

	cout << "a tree." << '\n';
}

void Input()
{
	while (true)
	{
		int edge_cnt = 0;
		set<int> v_node;
		map<int, vector<int>> nv;
		map<int, bool> nv_visit;
		int u, v;

		while (true)
		{
			cin >> u >> v;

			if (u == -1 && v == -1)
				return;

			if (u == 0 && v == 0)
				break;

			else
			{
				edge_cnt++;
				v_node.insert(v);

				nv_visit.insert({ u, false });
				nv_visit.insert({ v, false });

				nv[u].push_back(v);

				/*if (nv.find(u) == nv.end())
				{
					set<int> uv;
					uv.insert(v);
					nv.insert({ u, uv });
				}

				else
					nv[u].insert(v);*/
			}
		}

		if (u && v && nv_visit.size() != edge_cnt)
			cout << "Case " << ++k << " is ";
		else
			CheckTree(edge_cnt, v_node, nv, nv_visit);
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