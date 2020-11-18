#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 55
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> pos; // pos = posibles resultados
bool flag = false;

void printV(vector<int> v) {
	fore(i, 0, v.size()) cout << v[i] << " ";
	cout << endl;
}
vector<int> primes;
vector<bool> isPrime; // tamaño n 
void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
		primes.push_back(i);
		if(i <= limit)
		for(int j = i * i; j <= n; j += 2 * i)
			isPrime[j] = false;
		}
	}
}

int convert(vector<int> &v, int l, int r) {
	int num = v[r]; 
	if(!num) return 0;// 
	for(int i = r-1; i >= l; i--) num = num * 10 + v[i];
	return num;
}
void check(vector<int> &v) {
	for(int i = 0; i < v.size()-2; i++) {
		int n1 = convert(v, 0, i), n2, n3;
		for(int j = i+1; j < v.size()-1; j++) {
			n2 = convert(v, i+1, j), n3 = convert(v, j+1, v.size()-1);
			// tengo n1, n2, n3
			if(isPrime[n1] && isPrime[n2] && isPrime[n3]) {	
				pos.pb(n1*n2*n3);
				flag = true;
			}
		}
	}
}
int main() {
	optimizar_io
	primesSieve(10000000); // REFERENCE 

	string s; cin >> s; // <<----- string
	int res = 0;
	if(s.size() < 3) flag = false;
	else {
		// IMPORTANTE
		vector<int> v(s.size()); // input: string 01123
		fore(i, 0, s.size()) v[i] = s[i]-'0'; //v = [0, 1, 1, 2, 3]
		sort(all(v)); // ordenas el arreglo
		do {
			check(v);
			// fore(i, 0, v.size()) {
			// 	cout << v[i] << " ";
			// }
			// cout << endl;
		} while(next_permutation(all(v))); // [01123], -> [10123] -> [10213] ->

	}
	sort(all(pos));
	if(flag) cout << pos[0] << endl;
	else cout << "Bob lies" << endl;
}