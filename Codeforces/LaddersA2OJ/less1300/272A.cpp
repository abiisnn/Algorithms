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

bool winFriend(int players, int sum) {
	bool ans = false;
	if((sum % players)) ans = true;
	return ans;
}

int main() {
	optimizar_io

	int n, aux; 
	int totalFinger = 0;
	cin >> n;
	fore(i, 0, n) {
		cin >> aux;
		totalFinger += aux;
	}

	int ans = 0;
	fore(i, 1, 6) {
		if(winFriend(n+1, totalFinger + i - 1)) {
			ans++;
		}
	}
	cout << ans << endl;
}