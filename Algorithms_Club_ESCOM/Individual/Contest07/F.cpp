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
 	int N, M, K;
 	cin >> N >> M >> K;
 	vector<int> v(N);

 	lli need = 0, maxNumber = 0, minDif = 5000;
 	fore(i, 0, N) {
 		cin >> v[i];
 		if(v[i] > M) {
 			need += v[i] - M;
 			if(v[i]-M < minDif) minDif = v[i]-M;
 		}
 		if(v[i] < M) {

 		}
 		if(v[i] > maxNumber) maxNumber = v[i];

  	}
  	if(maxNumber == M) cout << "YES";
  	if(maxNumber  < M) {
  		int aux = (M - maxNumber) /
  		if(M - maxNumber /)
  	} 

 }