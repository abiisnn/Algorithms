#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define pairs pair<lli, lli>
#define fi first
#define se second
#define endl '\n'
#define N 3
typedef long long int lli;

lli calculate(lli x, lli y) {
	lli ans  = 0;
	if(x == y) {
		ans = 0;
	}
	else if((x < 0) && (y < 0)) {
		x *= -1LL;
		ans= x + y;
	} 
	else if((x >= 0) && (y >= 0)) {
		ans = max(x, y) - min(x, y);
	} else if(x < 0) {
		x *= -1LL;
		ans += x;
		ans += y;
	}
	return ans;
}
int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<lli> distance;
	map<lli, lli> m;
	vector<pairs> p;
	lli x, y, ans;
	lli max = 0, pos;
	fore(i, 0, n) {
		cin >> x >> y;
		p.pb(mk(x, y));
		ans = calculate(x, y);
		distance.pb(ans);
		if(ans > max) {
			max = ans;
		}
	}
	lli cont = 0;
	fore(i, 0, n) {
		// cout << distance[i] << " " << endl;
		if(distance[i] == max) {
			// cout << "Entre :)" << endl << endl;
			// cout << "Pair: " << p[i].first << " " << p[i].second << endl;
			// cout << "distance: " << distance[i] << endl;
			pos = p[i].first;
			// cout << "x " <<  pos << endl;
			m[pos] += 1;
			pos = p[i].second + 1;
			// cout << "y " <<  pos << endl;
			m[pos] += -1;
			cont++;
		}
	}
	lli sum, last = 0;
	max = 0;
	for(auto &i: m) {
		// cout << i.first << " " << i.second << endl;
		// cout << last + i.second << endl;
		sum = last + i.second;
		if(sum > max) {
		 	max = sum;
		}
		last = sum;
	}
	cout << max;
}