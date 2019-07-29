#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
string str, final;

void reverse(int a, int b) {
	int j = b;
	for(int i = a; i <= b; i++, j--) 
		final[j] = str[i];  
}

int main() {
	int group, fin;
	int i, j;
	while(cin >> group, group != 0) {
		cin >> str;
		final = str;
		group = str.length() / group;
		for(i = 0, fin = group - 1; i < str.length(); i += group, fin += group) {
			reverse(i, fin);
		}
		cout << final << endl;
	}
}