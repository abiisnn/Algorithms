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
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	string str;
	cin >> n >> m >> str;
	
	int ans = 0, dist = 0;
	vector<int> distances;
	for(int i = 1; i < str.size(); i++) {
		if(str[i] == '1') {
			distances.pb(dist+1);
			dist = 0;	
		} else dist++;
	}
	distances.pb(dist+1);
	bool flag = true;
	int salto = 0, sumAcum = 0, continuos = 0;
	for(int i = 0; i < distances.size(); i++) {
		if(distances[i] > m) {
			flag = false;
			break;
		}
		if(continuos + distances[i] > m) {
			salto++;
			continuos = distances[i];
		} else continuos += distances[i];
	}
	if(continuos <= m) salto++;
	else salto += 2;
	
	if(flag) cout << salto << endl;
	else cout << -1 << endl;
}

/*
8 4
10010101
01234567

1. Generar el vector de distancias
vector distancias // []
cont = 0
--> 1, 0
	cont=1;
--> 2, 0
	cont=2
--> 3, 1
	distancias.push_back(cont+1) // [3] 
	cont = 0
--> 4, 0
	cont=1
--> 5, 1
	distancias.push_back(cont+1) // [3, 2]
	cont = 0
--> 6, 0
	cont=1
--> 7, 1
	distancias.push_back(cont+1) // [3, 2, 2]

2. Sumas que podemos hacer <= k, k = 4
[3, 2, 2]
 0  1  2

bool flag = true;
int continuos = 0, saltos = 0
distancias[i] > k:
	flag = false
	break
if continuos + distancias[i] <= k:
	continuos += distancias[i]
else // >k
	salto++
	continuos = distancias[i]

-->0, 3
	3 > 4 NO
	(0+3) <= 4:
		continuos = 3
-->1, 2
	2 > 4 NO
	(3+2) <= 4 NO
	else:
		salto = 1
		continuos = 2
-->2, 2
	2 > 4 NO
	(2+2) <= 4: SI
		cotinuos = 4

continuos <= k
	salto++

*/