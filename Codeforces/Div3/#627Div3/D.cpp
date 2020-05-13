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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io

	int n;
	cin >> n;
	vector<lli> a(n), b(n), c(n);
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, n) cin >> b[i];
	fore(i, 0, n) c[i] = a[i] - b[i];
	sort(c.begin(), c.end());
	
	lli ans = 0;
	fore(i, 0, n){
		if(c[i] > 0) {
			vector<lli>::iterator low = std::lower_bound(c.begin(), c.end(), (-1*c[i])+1);
		    if(low != c.end()) {
		    	ans += i - int(low - c.begin());
		    }
		}
	}
	cout << ans << endl;
}

/*
ai + aj > bi + bj

ai - bi > bj - aj
i < j

4 8 2 6 2		a
4 5 4 1 3 		b
0 -3 2 -5 1 	bj - aj
0 3 -2 5 -1     ai -bi

0 --> -3, -5
3 -->  2, -5, 1
-2 --> -5
5 --> 1

7

ai + aj > bi + bj
ai - bi > bj - aj

ai - bi -bj + aj > 0
(ai - bi) + (aj - bj) > 0
ci + cj > 0
cj >= -ci + 1

4 8 2 6 2		a
4 5 4 1 3 		b
0 3 -2 5 -1     ai-bi = c

-2 -1 0 3 5 	c sorted

ans = 0
--> -2, i = 0
--> -1, i = 1
--> 3 ---> lower_bound(-2) => ans += 3 - 0 // 3
->  5 ---> lower_bound(-4) => ans += 4 - 0 // 7
*/