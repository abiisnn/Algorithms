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
typedef long long int lli;

int subarrayofX(vector<lli> a) {
	int sum = 0, l = 0, r = -1, ans = 0;
	while(r < a.size() - 1) {
		r++
		sum += a[r];
		if(sum == x) ans++;
		while((sum > x) && (l < a.size())) {
			sum -= a[l];
			l++;
		}
	}
}
int main() {
	// Read data
}