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

lli distance(lli a, lli b, lli c) {
	return abs(a-b) + abs(a-c) + abs(b-c);
}

int main() {
	optimizar_io
	int q;
	cin >> q;
	int moves[] = {0, 1, -1};
	while(q--) {
		lli a, b, c;
		cin >> a >> b >> c;
		lli dis = 100000000000;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					lli aux = distance(a-moves[i], b-moves[j], c-moves[k]); 
					if(aux < dis) dis = aux;
				}
			}
		}
		cout << dis << endl;
	}
}