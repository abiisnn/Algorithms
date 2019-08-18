#include<bits/stdc++.h> 
using namespace std; 
int n, r, t, cantidad, suma; 

int main() {
	cin >> t; 
	while(t--) {
		cin >> n >> r; 
		suma = 0; 
		while(n--) {
			cin >> cantidad; 
			suma = suma + cantidad; 	
		}
		if(suma + 1500 == r)
		       cout << "Correct" << "\n";
		else 
			cout << "Bug" << "\n"; 
	}
}