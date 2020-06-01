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
#define MAX 37
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

struct Trie {
	map<char, Trie *> ch;
	int freq;    
	Trie() { freq = 0; }
};
void insert(Trie *root, string str) {
	Trie *curr = root;
	for(int i = 0; i < str.size(); i++) {
		if(!curr->ch.count(str[i])) curr->ch[str[i]] = new Trie();
		curr = curr->ch[str[i]];
	}
	curr->freq++;
}
bool exist(Trie *root, string str) {
	Trie *curr = root;
	for(int i = 0; i < str.size(); i++) {
		if(!curr->ch.count(str[i])) return false;
		curr = curr->ch[str[i]];
	}
	return curr && curr->freq; 
}
bool existPrefix(Trie *root, string str) {
	Trie *curr = root;
	for(int i = 0; i < str.size(); i++) {
		if(curr->freq) return true;
		if(!curr->ch.count(str[i])) return false;
		curr = curr->ch[str[i]];
	}
	return curr && curr->freq; 
}

int main() {
	optimizar_io
	Trie *root = new Trie();
	int n, q; cin >> n >> q;
	string prefix;
	vector<string> words(n);
	fore(i, 0, n) cin >> words[i];
	fore(i, 0, q) {
		cin >> prefix;
		insert(root, prefix);
	}

	vector<string> ans;
	fore(i, 0, n) {
		if(!existPrefix(root, words[i])) ans.pb(words[i]);
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	fore(i, 0, ans.size()) cout << ans[i] << endl;
}