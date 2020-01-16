#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 10000005
#define OUT 10000000
 
vector<int> lp;
void lowestPrimeSieve(int n) {
	lp.resize(n + 1, 1);
	lp[0] = lp[1] = 0;
	for(int i = 2; i <= n; ++i) lp[i] = (i & 1 ? i : 2);
	
	int limit = sqrt(n);
	for(int i = 3; i <= limit; i += 2)
		if(lp[i] == i)
			for(int j = i * i; j <= n; j += 2 * i)
				if(lp[j] == j) lp[j] = i;
}
map<lli, lli> factor(int n) {
	map<lli, lli> f;
	while(n > 1) {
		int p = lp[n];
		int r = 0;
		while((n % p) == 0) {
			n /= p;
			r++;
		}
		f[p] = r;
	}
	return f;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> N(n, 0);
	vector<int> M(m, 0);
	vector<map<lli, lli>> facN;
	vector<map<lli, lli>> facM;
	map<lli, lli> numerator;
	map<lli, lli> denominator;
	map<lli, lli> gcd;
	map<lli, lli> gcdAux;
 
	for(int i = 0; i < n; i++) {
		cin >> N[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> M[i];
	}
	sort(N.begin(), N.end());
	sort(M.begin(), M.end());
	lowestPrimeSieve(max(N[n - 1], M[m - 1]) + 2);
 
	for(int i = 0; i < n; i++) {
		facN.push_back(factor(N[i]));
	}
	for(int i = 0; i < m; i++) {
		facM.push_back(factor(M[i]));
	}
	// Numerator
	for(int i = 0; i < facN.size(); i++) {
		for(auto &j : facN[i]) {
			numerator[j.first] += j.second;
		}
	}
	// Denominator
	for(int i = 0; i < facM.size(); i++) {
		for(auto &j : facM[i]) {
			denominator[j.first] += j.second;
		}
	}
 	
 	for(auto &i : numerator) {
 		gcd[i.first] = min(numerator[i.first], denominator[i.first]);
 	}
 	for(auto &i : denominator) {
 		gcd[i.first] = min(numerator[i.first], denominator[i.first]);
 	}
	for(auto &i : gcd) {
		numerator[i.first] -= gcd[i.first];
		denominator[i.first] -= gcd[i.first];  
	}
	
	// cout << "--------------------GCD:" << endl;
	// for(auto &i : gcd) {
	// 	cout << i.first << " " << i.second << endl;
	// }
	// cout << "--------------------" << endl;

	// Numerator
	gcdAux = gcd;
	for(int i = 0; i < facN.size(); i++) {
		for(auto &j : facN[i]) {
			int m = min(j.second, gcdAux[j.first]);
			// cout << "Minimo: " << m << endl;
			j.second -= m;
			gcdAux[j.first] -= m;
		}
	}

	// Numerator
	gcdAux = gcd;
	for(int i = 0; i < facM.size(); i++) {
		for(auto &j : facM[i]) {
			int m = min(j.second, gcdAux[j.first]);
			// cout << "Minimo: " << m << endl;
			j.second -= m;
			gcdAux[j.first] -= m;
		}
	}
	
	vector<int> ansNum;
 	vector<int> ansDen;
	for(auto &i : numerator) {
		int res = 1;
		for(int j = 0; j < i.second / 2; j++) {
			res *= i.first;
		}
		if(res > 1)
			ansNum.push_back(res);
		res = 1;
		for(int j = (i.second / 2); j < i.second; j++) {
			res *= i.first;
		}
		if(res > 1)
			ansNum.push_back(res);
	}

	for(auto &i : denominator) {
		int res = 1;
		for(int j = 0; j < i.second / 2; j++) {
			res *= i.first;
		}
		if(res > 1)
			ansDen.push_back(res);
		res = 1;
		for(int j = (i.second / 2); j < i.second; j++) {
			res *= i.first;
		}
		if(res > 1)
			ansDen.push_back(res);
	}

	if(ansNum.size() == 0) ansNum.push_back(1);
	if(ansDen.size() == 0) ansDen.push_back(1);	
	
	cout << ansNum.size() << " " << ansDen.size() << endl;
 	for(int i = 0; i < ansNum.size(); i++)
 		cout << ansNum[i] << " ";
 	cout << endl;
 	for(int i = 0; i < ansDen.size(); i++)
 		cout << ansDen[i] << " ";
 	cout << endl;
}