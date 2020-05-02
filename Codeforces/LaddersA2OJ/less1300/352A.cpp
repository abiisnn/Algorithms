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
	optimizar_io
	int n = 0, num5 = 0, zeros = 0;
	char aux;
 	cin >> n;
 	fore(i, 0, n) {
 		cin >> aux;
 		if(aux == '5') num5++;
 	}
	zeros = n - num5;
	if(num5 >= 9 && zeros >= 1){
		fore(i, 0, 9*(num5/9)) cout << 5;
		fore(i, 0, zeros) cout << 0;
		cout << endl;
	} else if(zeros >= 1) cout << 0 << endl;
	else cout << "-1" << endl;
}