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
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<char> aux = {'O', 'L', 'Z', 'E', 'S', 'B', 'T', 'B'};

struct TrieNode {
	map<char, TrieNode *> children;
	int freq;		    
	TrieNode() {freq = 0;}
};
void insert(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) {
			current->children[target[i]] = new TrieNode();
		}
		current = current->children[target[i]];
	}
	current->freq++;
}
bool exist(TrieNode *root, string target) {
	TrieNode *current = root;
	for(int i = 0; i < target.size(); i++) {
		if(!current->children.count(target[i])) return false;
		current = current->children[target[i]];
	}
	return current && current->freq; 
}
void change(string &w) {
	fore(i, 0, w.size()) {
		if(w[i] >= 48 && w[i] <= 56) {
			w[i] = aux[w[i]-'0'];
		}
	}
}
int main() {
	TrieNode *root = new TrieNode();
	int n, q; cin >> n >> q;
	string w;
	fore(i, 0, n) {
		cin >> w;
		insert(root, w);
	}
	fore(i, 0, q) {
		cin >> w;
		change(w);
		bool flag = false;
		fore(j, 0, w.size()) {
			fore(k, 0, w.size()+1-j) {
				string eva = w.substr(j, k);
				if(exist(root, eva) && eva.size()) {
					flag = true; 
					break; 
				}
			}
			if(flag) break;
		}
		if(flag) cout << "INVALID" << endl;
		else cout << "VALID" << endl;	
	}
}