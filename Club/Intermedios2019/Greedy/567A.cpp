// https://codeforces.com/contest/567/problem/A
#include<bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000000000000ll;;

long long int distance(int x1, int x2) {
	return x2 - x1;
}

int main() {
	int n;
	long long int allBefore, allAfter, maxD, minD;
	long long int back, next, number;

	vector<long long int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> number;
		v.push_back(number);
	}

	allBefore = 0;
	allAfter = distance(v[0], v[n - 1]);
	maxD = max(allBefore, allAfter);

	back = inf;
	next = distance(v[0], v[1]);
	minD = min(back, next);

	cout << minD << " " << maxD << endl;

	for(int i = 1; i < n - 1; i++) {
		allBefore += next;
		allAfter -= next;
		maxD = max(allBefore, allAfter);

		back = next;
		next = distance(v[i], v[i+1]);
		minD = min(back, next);

		cout << minD << " " << maxD << endl;
	}

	cout << next << " " <<  distance(v[0], v[n - 1])  << endl;


}