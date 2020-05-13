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
#define MAX 100005
typedef long long int lli;

vector<char> pattern = {'R', 'G', 'B'};
int calculate(string &seq, int i, int k) {
	int l = 0, r = 0;
	int mod = pattern.size();
	int moves = seq.size()+5, auxMoves = 0, auxi = i;
	while(r < k) {
		if(pattern[i % mod] != seq[r]) auxMoves++;
		i++; r++;
	}
	if(auxMoves < moves) moves = auxMoves;
	while(r < seq.size()) {
		l++;
		if(seq[l-1] != pattern[auxi % mod]) auxMoves--; 
		if(seq[r] != pattern[i % mod]) auxMoves++;
		if(auxMoves < moves) moves = auxMoves;
		auxi++; i++; r++;
	}
	return moves;
}

int main() {
	optimizar_io
	int q, n, k;
	string seq;

	cin >> q;
	while(q--) {
		cin >> n >> k >> seq;
		int ans = seq.size()+5;
		fore(i, 0, pattern.size()) {
			int moves = calculate(seq, i, k);
			if(moves < ans) ans = moves;
		}
		cout << ans << endl;
	}
}