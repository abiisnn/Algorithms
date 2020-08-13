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
const double PI = acos(-1.0);
double eps = 1e-6;
bool ge(double a, double b){return a-b > eps;}

int main() {
	optimizar_io
	int n, k; cin >> n >> k;
	vector<int> v(n), acum(n); 
	fore(i, 0, n) cin >> v[i];

	acum[0] = v[0];
	fore(i, 1, n) acum[i] = acum[i-1] + v[i];
	
	double best = 0.0, sum = 0.0;
	fore(i, 0, n-k+1) {
		fore(j, i+k-1, n) {
			if(i == 0) sum = double(acum[j]);
			else sum = double(acum[j] - acum[i-1]);
	 		double aux = sum / double(j - i + 1.0);
			if(ge(aux, best)) best = aux;
		}
	}
	cout << setprecision(15) << fixed;
	cout << best << endl;
}