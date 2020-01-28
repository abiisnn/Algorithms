//https://codeforces.com/problemset/problem/228/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	map<lli, int> m;
	int i;
	lli aux;
	fore(i, 0, 4) {
		cin >> aux;
		m[aux]++;
	}
	cout << 4 - m.size() << endl;
}