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

int main() {
	int ab, ac, bc;
	int a, b, c;
	cin >> ab >> ac >> bc;

	a = sqrt((ab * ac) / bc);
	b = ab / a;
	c = ac / a;
	cout  << a * 4 + b * 4 + c * 4 << endl;
}