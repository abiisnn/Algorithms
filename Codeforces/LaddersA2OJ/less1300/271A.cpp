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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isBeutiful(int n) {
	bool ans = true;
	string num = to_string(n);
	set<int> se;
	fore(i, 0, num.size()) {
		if(se.count(num[i])) {
			ans = false;
			break;
		}
		se.insert(num[i]);
	}
	return ans;
}
int main() {
	optimizar_io
	int n;
	cin >> n;
	bool flag = true;
	n++;
	while(flag) {
		if(isBeutiful(n)) {
			cout << n << endl;
			break;
		} 
		n++;
	}
}