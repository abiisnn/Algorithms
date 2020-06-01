#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<set<int>> memo(MAX, set<int>());
vector<bool> visited(MAX, false);
struct Node {
    vector<Node*> children;
    int data;
    Node(int v) : data(v) {}
};
/* Return true if Node n exist in the Binary Tree and 
   save the path in the vector. */
bool getPath(Node *root, Node *n, set<int> &path) {
    if(!root) return false; // if(root == NULL)
    if(visited[root->data]) {
    	path.insert(memo[root->data].begin(), memo[root->data].end());
    	return true;
    }
    visited[root->data] = true;
    if(root->data == n->data) {
        path.insert(root->data);
        return true;
    }
    fore(i, 0, root->children.size()) {
		if(getPath(root->children[i], n, path)) {
			path.insert(root->data);
			return true;
		}    	
    }
  return false;
}
int main() {
	optimizar_io
	int n, m, aux;
	cin >> n >> m;
	vector<vector<int>> projects(MAX, vector<int>(0));
	fore(i, 0, n) {
		cin >> aux;
		projects[aux].pb(i+1);
	}
	vector<Node *> tree(n+1);

	fori(i, 1, n) {
		Node *node = new Node(i);
		tree[i] = node; 
	}
	Node *root;
	fore(i, 0, n) {
		cin >> aux;
		if(aux)	tree[aux]->children.pb(tree[i+1]);
		else {
			root = tree[i+1];
		}
	}
	fori(i, 1, n) {
		set<int> aux;
		if(getPath(root, tree[i], aux)) {
			memo[i] = aux;
		}
		aux.clear();
	}

	fori(i, 1, m) {
		set<int> final;
		fore(j, 0, projects[i].size()) {
			int index = projects[i][j];
			final.insert(memo[index].begin(), memo[index].end());
		}
		cout << final.size() << " ";
		final.clear();
	}
	cout << endl;
}