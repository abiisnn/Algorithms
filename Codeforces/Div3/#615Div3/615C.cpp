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

// O(sqrt(N)) 
vector<lli> getDivisors(lli n) { 
	vector<lli> divs; 
	for (lli i = 1; i * i <= n; i++) 
		if (!(n % i)) { 
			divs.push_back(i); 
			if (i * i != n) divs.push_back(n / i); 
		} 
	return divs; 
}
lli minDiv(lli n, lli diferent) {
	vector<lli> div = getDivisors(n);
	sort(div.begin(), div.end());
	vector<lli>::iterator upper;
	upper = std::upper_bound(div.begin(), div.end(), diferent); 
	if(upper != div.end()) {
		lli ans = *(upper);
		return ans;
	} else return 1;
}
void find(lli n) {
	lli a, b, c;
	a = minDiv(n, 1);
	b = minDiv(n/a, a);
	c = n / (a*b);
	if((a != b) && (a != c) && (b != c) && (a > 1) && (b > 1) && (c > 1)) {
		cout << "YES" << endl << a << " " << b << " " << c << endl;
	} else cout << "NO" << endl;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	lli n;
	cin >> t;
	while(t--) {
		cin >> n;
		find(n);	
	}
}