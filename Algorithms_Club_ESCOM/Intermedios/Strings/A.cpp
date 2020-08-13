#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
/* Abigail Nicolas Sayago.
	This is a basic implementation of a trie structure,
*/
struct TrieNode {
	map<char, TrieNode *> children; // Reference to the next character
	int freq, prefix;
	TrieNode() { 
		prefix = 0;
	}
};
void insert(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) {
			current->children[target[i]] = new TrieNode();
		}
		current->prefix++;
		current = current->children[target[i]];
	}
	current->prefix++;
}
int prefix(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) return 0;
		current = current->children[target[i]];
	}
	if(current) return current->prefix;
	return 0; 
}

int main() {
	optimizar_io
	TrieNode *root = new TrieNode();
	string s;
	int n, q; cin >> n >> q;

	fore(i, 0, n) {
		cin >> s;
		insert(root, s);
	}
	fore(i, 0, q) {
		cin >> s;
		cout << prefix(root, s) << endl;
	}
}