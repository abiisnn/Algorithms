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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-6;
struct UnionFind {
	int n;
	vector<int> id, size;

	UnionFind(int N) : n(N), id(N), size(N, 1) { // O(N)
		for(int i = 1; i <= n; i++) {
			id[i] = i;
		}
	}
	int find(int i) { // O(log*N)
		while(i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	void join(int i, int j) { //O(log*N)
		i = find(i), j = find(j);
		if(i == j) return;
		if(size[i] < size[j]) { // Choosing by weidth
			std::swap(i, j);
		}
		n--; 
		id[j] = i;
		size[i] += size[j];
	}
	bool connected(int i, int j) { // O(log*N)
		return find(i) == find(j);
	}
	int numberSets() {
		return n;
	}
};

int main() {
	optimizar_io
	int n, e, d;
	vector<set<int>>respuestas(n, set<int>);
	vector<set<int>> entrada(n, set<int>);
	vector<int> minutos(n);
	fore(i, 0, n) {
		cin >> minutos[i] >> d;
		fore(j, 0, d) {

		}
	}
}