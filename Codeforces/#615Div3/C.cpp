#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

int isPrime(lli &n) {
	cout << "--------number: " << n << endl;
	lli limit = sqrt(n);
	int ans = 0;
	int i = 0; 
	for(i = 2; i <= limit; i++) {
		if((n % i) == 0) {
			ans = i; 
		}
	}
	cout << "ans: " << ans << endl;
	return ans;
}

void find(lli n) {
	bool flag = true;
	vector<lli> numbers(4, 0);
	numbers[0] = isPrime(n);
	if(numbers[0] == 0) {
		cout << "NO" << endl; 
	} else {
		numbers[1] = isPrime(n);
		lli aux = n % numbers[1];
		if((numbers[1] == 0) && (() == 0)) {
			cout << "NO" << endl;
		} else {
			numbers[2] = isPrime(n);
			// cout << "----" << endl;
			// cout << "a: " << a << " n: " << n << endl;
			// cout << "b: " << b << " c: " << c << endl;
			numbers[3] = n;
			//sort(numbers.begin(), numbers.end());
			for(int i = 0; i < 4; i++) {
				cout << numbers[i] << " ";
			}	cout << endl;
			if((numbers[2] == 0)) {
				if((numbers[0] != numbers[1]) && (numbers[1] != numbers[3]) && (numbers[3] != numbers[0])) {
					cout << "YES" << endl;
					cout << numbers[0] << " " << numbers[1] << " " << numbers[3] << endl;
					cout << endl;
				} else cout << "NO" << endl;
			} else {
				numbers[1] *= numbers[2];
				if((numbers[0] != numbers[1]) && (numbers[1] != numbers[3]) && (numbers[3] != numbers[1])) {
					cout << "YES" << endl;
					cout << numbers[0] << " " << numbers[1] << " " << numbers[3] << endl;
				} else cout << "NO" << endl;
			}
			// if((a != b) && (b != n) && (a != n) && (n != 1)) {
			// 	cout << "YES" << endl;
			// 	cout << a << " " << b << " " << n << endl;
			// }
			// else cout << "NO" << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	lli n, total, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		find(n);	
	}
}