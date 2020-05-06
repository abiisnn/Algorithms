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

vector<int> intersection(vector<int> &a, vector<int> &b) {
	vector<int> c;
	int i = 0, j = 0;
	while((i < a.size())  && (j < b.size())) {
		if(a[i] < b[j]) i++;
		else if(b[j] < a[i]) j++;
		else {
			c.pb(a[i]);
			i++; j++;
		}
	}
	return c;
}

int main() {
	// Read data
	vector<int> ans = intersection(a, b);
}