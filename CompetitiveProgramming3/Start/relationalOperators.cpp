#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	long long a, b;
	scanf("%d", &tc);
	while(tc--){
		cin >> a >> b;
		if(a < b) 
			cout << "<" << endl;
		else if(a > b)
			cout << ">" << endl;
		else 
			cout << "=" << endl;
	}
	return 0;
}