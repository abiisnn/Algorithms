#include<bits/stdc++.h>
#define MAX 2500000
#define N 10000000
using namespace std;
typedef long long int lli;
lli Divisors(lli n) {
	lli div = 0;
	for(lli j = 1; j <= sqrt(n); j++) {
		if(n % j == 0) div += 2;
		if(j == sqrt(n) && sqrt(n)*sqrt(n) == n) div--;
	}
	return div;
}

int main() {
	vector<lli> sequence(N);
	sequence[0] = 0, sequence[1] = 1;
	for(int i = 2; i < N; i++) {
		sequence[i] = sequence[i-1] + i;
	}

	// cout << "sequence: " << endl;
	// for(int i = 0; i < N; i++) {
	// 	cout << sequence[i] << " ";
	// }
	// cout << endl;
	lli greatest = 0;
	for(int i = 0; i < N; i++) {
		lli div = Divisors(sequence[i]);
		if(div > 500) {
			greatest = sequence[i];
			break;
		}
	}
	cout << greatest << endl;

}