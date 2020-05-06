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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int n;
	cin >> n;
	string str;
	vector<vector<int>> matrix(n, vector<int>(27));
	fore(i, 0, n) {
		cin >> str;
		cout << str << endl;
		fore(j, 0, str.size()) matrix[i][str[j] - 'a']++;
	}
	vector<int> even(27);
	vector<int> odd(27);
	fore(i, 0, n) {
		fore(j, 0, 27) {
			if(matrix[i][j]&1) odd[j]++;
			else even[j]++;
		}
	}
	fore(i, 0, n) {
		fore(j, 0, 27) {
			cout << matrix[i][j] << " ";
		} cout << endl;
	}
	cout << "EVEN:" << endl;
	fore(i, 0, 27) {
		cout << even[i] << " ";
	} cout << endl;
		cout << "ODD:" << endl;
	fore(i, 0, 27) {
		cout << odd[i] << " ";
	} cout << endl;
	lli ans = 0;
	for(int i = 0; i < n; i++) {
		cout << "============= vector:" << i << endl;
		fore(j, 0, 27) cout << matrix[i][j] << " ";
		cout << endl;
		for(int j = 0; j < 27; j++) {
			// cout << "-->" << matrix[i][j] << endl;
			if(matrix[i][j]&1) {
				// cout << "Soy impar y hay: " << even[j]-1 << endl;
				cout << odd[j] - 1 << " ";
			} else cout << even[j] -1 << " ";  
		}
		cout << endl;
		for(int j = 0; j < 27; j++) {
			if(matrix[i][j]&1) {
				cout << even[j] << " ";
			} else cout << odd[j] << " ";
		}
		cout << endl;
	}
	cout << ans << endl;

}