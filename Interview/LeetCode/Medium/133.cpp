#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int val): val(val) {
        neighbors = vector<Node*>();
    }
};
 Node* cloneDFS(map<int, Node*> &visited, Node* original) {
    if(visited[original->val]) return visited[original->val];

    Node* copy = new Node(original->val);

    visited[original->val] = copy;
    for(int i = 0; i < original->neighbors.size(); i++) {
        copy->neighbors.push_back(cloneDFS(visited, original->neighbors[i]));
    }
    return copy;
}
Node* cloneGraph(Node* node) {
    if(!node) return NULL;
    map<int, Node*> visited;
    
    Node *clone = cloneDFS(visited, node);
    
    return clone;
}
void print(map<int, bool> &visited, Node *graph) {
    if(!graph) return;
    if(visited[graph->val]) return;
    visited[graph->val] = true;

    cout << "--> " << graph->val << endl;
    for(int i = 0; i < graph->neighbors.size(); i++) {
        cout << &graph->neighbors[i] <<" " << graph->neighbors[i]->val << endl;
    }
    for(int i = 0; i < graph->neighbors.size(); i++) {
        print(visited, graph->neighbors[i]);
    }
}

void printGraph(Node *graph) {
    if(!graph) return;
    map<int, bool> visited;
    print(visited, graph);
}
