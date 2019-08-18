#include<bits/stdc++.h>
 using namespace std;
 
int main() {
	int tc, tam, flag, number;
	string A, B;
	long long int result;
	cin >> tc;
	while(tc--) {
		cin >> tam;
		cin >> A >> B;
		result = 1; flag = 1;
		for(int i = 0; i < tam; i++) {
			if((A[i] == '1') && (B[i] == '0')) {
				flag = 0;
				cout << "IMPOSSIBLE" << endl; break;
			}
			else if((A[i] == '1') && (B[i] == '1')) {
				result %= 1000000007; 
				result *= 2;
			}
		} 
		result %= 1000000007; 
		if(flag)
			cout << result << endl;
	}
}