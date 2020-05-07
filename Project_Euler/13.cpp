#include<bits/stdc++.h>
using namespace std;
/* Return a string that represent sum of a and b. 
   Strings a and b, doesnt have to contain unnecessary
   zeros, ie. 0001, 01223. */
string sumStrings(string a, string b) { // O(max(|a|, |b|))
	int zeros = std::max(a.size(), b.size()) - std::min(a.size(), b.size());
	string z(zeros, '0');
	if(a.size() < b.size()) {
		a = z + a;
	} else b = z + b;

	z.resize(a.size(), '0');
	int ans, num, carry = 0;
	for(int i = a.size()-1; i >= 0; i--) {
		ans = a[i]-'0' + b[i]-'0' + carry;
		carry = 0;
		if(ans > 9) {
			carry = 1;
			ans %= 10;
		}
		z[i] = ans + '0';
	}
	if(carry) z = char(carry + '0') + z;
	return z;
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string ans, last = v[0];
	for(int i = 1; i < n; i++) {
		ans = sumStrings(last, v[i]);
		last = ans;
	}
	cout << ans << endl;
}