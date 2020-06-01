#include<bits/stdc++.h>
using namespace std;
int char_to_int(char n) { return n - '0'; }
string multiply(string a, char b) {
	string ans = "";
	int down = char_to_int(b), carry = 0;
	for(int i = a.size()-1; i >= 0; i--) {
		int mul = char_to_int(a[i]) * down + carry;
		carry = (mul / 10);
		mul = mul % 10;
		ans = char(mul + '0') + ans; 
	}
	if(carry) ans = char(carry + '0') + ans;
	return ans;
}
int main() {
	string ans = "1";
	char m = '2';
	for(int i = 0; i < 5; i++) {
		cout << ans << " * "<< m << endl;
		ans = multiply(ans, m);
		cout << ans << endl;
	}
	cout << ans << endl;
	int sum = 0;
	for(int i = 0; i < ans.size(); i++) {
		sum += char_to_int(ans[i]);
	} 
	cout << sum << endl;
}