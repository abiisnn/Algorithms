#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 40
#define MAXn 105
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<vector<set<int>>> memory(MAX, vector<set<int>>(MAX));
int L, C; 
void printMap(map<char, int> &hola) {
	cout << "========== mapa aqui" << endl;
	for(auto &i: hola) {
		cout << i.fi << " " << i.se << endl;
	}
}
void findAnagrams(vector<string> &g, string word, int numW) {
	map<char, int> bucket;
	for(auto &i: word) bucket[i]++;
	printMap(bucket);
	// Horizontal:
	fore(i, 0, L) {
		map<char, int> curBuc;
		int l = 0;
		for(int j = 0; j < C; j++) {
			char charHere = g[i][j];			
			curBuc[charHere]++;
			if(j - l + 1 == word.size()) {
				if(curBuc == bucket) {
					fori(k, l, j) memory[i][k].insert(numW);
				}
				curBuc[g[i][l]]--;
				l++;
			}
		}
	}
	// vertical
	for(int i = 0; i < C; i++) {
		map<char, int> curBuc;
		int l = 0;
		for(int j = 0; j < L; j++) {
			char charHere = g[j][i];
			curBuc[charHere]++;
			if(j - l +1== word.size()) {
				if(curBuc == bucket) {
					fori(k, l, j) memory[k][i].insert(numW);
				}
				curBuc[g[l][i]]--;
				l++;
			}
		}
	}
	// Diagonal hacia abajo:
	for(int i = 0; i < L; i++) { 
		int x = i, y = 0; 
		int laux = i, raux = 0;
		map<char, int> curBuc;
		while(x < L && y < C) {
			char charHere = g[x][y];
			curBuc[charHere]++;
			if(y - raux + 1 == word.size()) {
				if(curBuc == bucket) {
					int h = raux;
					fori(k, laux, y) {
						memory[h][k].insert(numW);
						h++;
					}
				}
				curBuc[g[laux][raux]]--;
				laux++, raux++;
			}
			x++; y++;
		}
	}
	// Diagonal hacia horizontal:
	for(int i = 0; i < C; i++) { 
		int x = 0, y = i; 
		int laux = 0, raux = i;
		map<char, int> curBuc;
		while(x < L && y < C) {
			char charHere = g[x][y];
			curBuc[charHere]++;
			if(y - raux + 1 == word.size()) {
				printMap(curBuc);
				if(curBuc == bucket) {
					int h = raux;
					fori(k, laux, y) {
						memory[h][k].insert(numW);
						h++;
					}
				}
				curBuc[g[laux][raux]]--;
				laux++, raux++;
			}
			x++; y++;
		}
	}
	// Diagonal hacia abajo:
	int needhere = 1;
	for(int i = 0; i < min(L, C); i++) { 
		int x = i, y = 0;
		int times = 0;
		int xaux = x, yaux = 0;
		map<char, int> curBuc;
		while(times < needhere) {
			times++;
			char charHere = g[x][y];
			curBuc[charHere]++;
			if(x - xaux + 1 == word.size()) {
				printMap(curBuc);
				if(curBuc == bucket) {
					int h = yaux;
					for(int k = xaux; k >= x; k--) {
						memory[k][h].insert(numW);
						h--;
					}
				}
				curBuc[g[xaux][yaux]]--;
				xaux--; yaux++;
			}
			x--; y++;
		}
		needhere++;
		if(needhere == min(L, C)) needhere = min(L,C);
	}
	int col = C-1;
	for(int i = 0; i < C; i++) {
		int x = L-1, y = C;
		int times = 0;
		int xaux = L-1, yaux = C;
		map<char, int> curBuc;
		while(times < needhere) {
			times++;
			char charHere = g[x][y];
			curBuc[charHere]++;
			if(x - xaux + 1 == word.size()) {
				printMap(curBuc);
				if(curBuc == bucket) {
					int h = yaux;
					for(int k = xaux; k >= x; k--) {
						memory[k][h].insert(numW);
						h--;
					}
				}
				curBuc[g[xaux][yaux]]--;
				xaux--; yaux++;
			}
			x--; y++;
		}
		needhere++;
		if(needhere == min(L, C)) needhere = min(L,C);
	}

}
int main() {
	optimizar_io

	cin >> L >> C;
	vector<string> grid(L, "");
	fore(i, 0, L) cin >> grid[i];

	int n; cin >> n;
	vector<string> words(n, "");
	fore(i, 0, n) cin >> words[i];

	fore(i, 0, n) {
		findAnagrams(grid, words[i], i+1);
	}

	int total = 0;
	fore(i, 0, L) {
		fore(j, 0, C) {
			if(memory[i][j].size() >= 2) {
				cout << "pos: " << i << " " << j<< endl;
				total++;
			}
		}
	}



	cout << total << endl;
}