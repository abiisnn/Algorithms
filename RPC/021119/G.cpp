#include<bits/stdc++.h>
#define MOD 1000000007
#define TAM 20
typedef long long int lli;
using namespace std;


int main() {
	lli a, maxOdd, totalSum;
	string srt;
	vector<lli> bucket(20, 0);
	cin >> a >> srt;
	// Fill bucket
	for(int i = 0; i < srt.size(); i++) {
		bucket[srt[i] - 97] += 1;
	}
	// Find Max Odd
	maxOdd = 0;
	for(int i = 0; i < bucket.size(); i++) {
		if(bucket[i] & 1) 
			if(bucket[i] > maxOdd) maxOdd = bucket[i];
	}
	// Total sum
	totalSum = 0;
	for(int i = 0; i < bucket.size(); i++) {
		if(bucket[i] & 1) {
			if(bucket[i] == maxOdd) {
				totalSum += ((maxOdd - 1) / 2) + 1;
				maxOdd = 0;
			} else {
				totalSum += ((bucket[i] - 1) / 2); 
			}
		} else {
			totalSum += (bucket[i] / 2);
		}
	}
	cout << totalSum;
	return 0;
}