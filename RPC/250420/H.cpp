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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli formula(lli n) {
	lli f = 2 * ((n * (n+1)) / 2);
	lli a = (n * (n-1)) / 2;
	return f + a;
}
string sumar(string a, int n) {
	bool carry = false;
	int ca = 0;
	for(int i = a.size()-1; i >= 0; i--) {
		if(carry) {
			a[i] = (a[i] -'0') + ca;
			carry = false;
		}
		int num = a[i] - '0';
		cout << "num: " << num << endl;
		if(num + n > 9) {
			carry = true;
			ca = 1;
			a[i] = (char)((num + n) % 10);
		} else a[i] = char(num + n);
	}
	string ans = a;
	if(carry) {
		ans = "1" + a;
	}
	return ans;
}

int main() {
	optimizar_io
	string h;
	cin >> h;
	int inicio = h.size()-3;
	int fin = h.size()-4;
	if(h.size() < 3) {
		inicio = 0;
		fin = 0;;
	}
	string lastDig = h.substr(inicio, 3);
	// fore(i, 1, 100000) {
	// 	lli ans = formula(i);
	// 	if((ans % 4) == 0) cout << i << ": " << ans << endl; 
	// }
	// cout << "lastDig: " << lastDig << endl;
	int num;
	std::istringstream(lastDig) >> num;
	// cout << "lastDig en number: " << num << endl;
	int aux = num;
	num = num-1;
	bool flag = true;
	int next = 0, cont = 0;
	while(flag) {
		if((num % 4) == 0 && (num % 8) != 0) {
			flag = false;
			next = num;
		} 
		cont++;
		num++;
	}
	next++;
	// cout << "next: " << next << endl;
	// cout << next - 5 << endl;
	// cout << next + 3 << endl;
	// cout << num << endl;
	// cout << "fin:" << fin << endl;
	if(next - 5 >= aux) {
			cout << h.substr(0, fin);
			cout << next -5 << endl;
	}
	else if(next >= aux) {
		cout << h.substr(0, fin);
		cout << next << endl;
	}
	else {
		h = sumar(h, 3);
		cout << h.substr(0, fin);
		cout << next + 3 << endl;

	}
}