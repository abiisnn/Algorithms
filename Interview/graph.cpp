#include<bits/stdc++.h>
using namespace std;

struct Graph {
	int r;
	int index;
	vector<Graph *> neighbor;
};
bool dfs(Graph* from, Graph* to, vector<bool> &visited) {
	int flag = 0;
	if (from == to) return true;
	if(visited[from->index]) return false;
	if(!visited[from->index])
		visited[from->index] = true;
	for (int i = 0; i < from->neighbor.size(); i++) {
		bool ans = dfs(from->neighbor[i], to, visited);
		if (ans) return true;
	}
	return false;
}
int bfs(Graph* from, Graph* to, vector<bool> &visited) {
	queue<pair<Graph*, int>> q;
	int nivel = 0;
	q.push({from, nivel});
	while(!q.empty()) {
		pair<Graph*, int> g = q.front();
		q.pop();		
		if(visited[g.first->index]) continue;
		else {
			visited[g.first->index] = true;
			if(g.first == to) {
				return g.second;
			}
			for(int i = 0; i <g.first->neighbor.size(); i++) {
				cout << g.first->neighbor[i]->index << endl;
				q.push({g.first->neighbor[i], g.second + 1});
			}
		}
	}
	return -1;
}

// bool dfs(Graph* from, Graph* to, vector<bool> &visited) {
// 	int flag = 0;
// 	if (from == to) return true;
// 	if(visited[from->index]) return false;
// 	if(!visited[from->index])
// 		visited[from->index] = true;
// 	for (int i = 0; i < from->neighbor.size(); i++) {
// 		bool ans = dfs(from->neighbor[i], to, visited);
// 		if(ans) flag = 1;
// 	}
// 	if(flag) return true;
// 	else return false;
// }

int main() {
	int nNodes, idGraph, nNeighbor, neigh;
	int start, end;
	cin >> nNodes;
	vector<Graph *> nodes(nNodes);
	vector<bool> visited(nNodes, false);
	for (int i = 0; i < nNodes; i++) {
		nodes[i] = new Graph();
		nodes[i]->index = i;
	}
	for (int i = 0; i < nNodes; i++) {
		cin >> idGraph >> nNeighbor;
		for (int j = 0; j < nNeighbor; j++) {
			cin >> neigh;
			nodes[i]->neighbor.push_back(nodes[neigh]); 		
		}
	}
	cin >> start >> end;
	
	// for(int i = 0; i < nodes.size(); i++) {
	// 	Graph * g = nodes[i];
	// 	cout << "NODE: " << i << " neighbor:" << endl;
	// 	for(int j = 0; j < nodes[i]->neighbor.size(); j++) {
	// 		cout << nodes[i]->neighbor[j]->index << endl;
	// 	}
	// }
	cout << bfs(nodes[start], nodes[end], visited) << endl;

	// if (bfs(nodes[start], nodes[end], visited)) 
	// 	cout << "Yes" << endl;
	// else cout << "NO" << endl;


	// if (dfs(nodes[start], nodes[end], visited)) 
	// 	cout << "Yes" << endl;
	// else cout << "NO" << endl;
}