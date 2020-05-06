#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

struct datos {
	lli s;
}
datos ST[2 * 2^(log2(n)) + c];
lli num[n];

lli f(datos a, datos b) {
	return a.s + b.s;
}

// Construir Segment Tree
void init(int nodo, int ini, int fin) {
	if(ini == fin) {
		ST[nodo].s = num[ini];
	} else {
		int m = (ini + fin) / 2;
		ini(nodo*2, ini, m);
		ini(nodo*2 + 1, m+1, fin);
		ST[nodo].s = f(ST[nodo*2], ST[nodo*2 + 1]);
	}
}

// Actualización
void update(int nodo, int ini, int fin, int x, int val) {
	if(x < ini or fin < x) {
		ST[nodo].s = val;
	} else {
		int m = (ini + fin) / 2;
		ini(nodo*2, ini, m, x, val);
		ini(nodo*2 + 1, m+1, fin, x, val);
		ST[nodo].s = f(ST[nodo*2], ST[nodo*2 + 1]);
	}
}

// Query
lli query(int nodo, int ini, int fin, int l, int r) {
	
}