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

bool isVowel(char a) {
	if(a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u' or a == 'y') {
		return true;
	}
	return false;
}

int main() {
	optimizar_io
	int n;
	cin >> n;
	string str;
	cin >> str;
	int vowel = 0;
	string ans = "";
	fore(i, 0, str.size()) {
		if(isVowel(str[i])) {
			vowel++;
			if(vowel == 1) {
				ans += str[i];
			}
		} else {
			ans += str[i];
			vowel = 0;
		}
	}
	cout << ans << endl;
}