// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2542
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main() {
	int t, answer, n;
	char a;
	cin >> t;

	answer = 1;
	while(t) {
		cin >> n;
		answer = n * 567;
		answer /= 9;
		answer += 7492;
		answer *= 235;
		answer /= 47;
		answer -= 498;
		std::string out_string;
		std::stringstream ss;
		ss << answer;
		out_string = ss.str();
		if(out_string.length() > 1) {
			a = out_string[out_string.length() - 2];
		}
		else
			a = '0';
		cout << a << endl;
		t--;
	}
}