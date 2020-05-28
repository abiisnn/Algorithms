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
#define MAX 10000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	fore(i, 0, n) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> firstPart(n*n), secondPart(n*n);
	int k = 0;
	fore(i, 0, n) {
		fore(j, 0, n) {
			firstPart[k] = a[i] + b[j];
			secondPart[k] = c[i] + d[j];
			k++;
		}
	}	
	sort(firstPart.begin(), firstPart.end());
	int cont = 0;

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds; 
	fore(i, 0, secondPart.size()) {
	    bounds = std::equal_range(firstPart.begin(), firstPart.end(), -secondPart[i]);
	    if(bounds.first != firstPart.end()) {
	    	if((*bounds.first) == -secondPart[i]) {
		    	int l = bounds.first - firstPart.begin();
		    	int r = bounds.second - firstPart.begin();
		    	cont += r - l;
	    	}
	    }
	}
	cout << cont << endl;
}