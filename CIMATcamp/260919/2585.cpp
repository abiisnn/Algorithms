#include<bits/stdc++.h>
using namespace std;

int main() {
	char a;
	int ans = 0, b = 0;
	int white, black;
	white = 0; black = 0;
	while(cin >> a, a != " ") {
		if(a == '.') white++;
		else black++;
	}
	if(!black) cout << "Rabbit";
	else {

	}
}