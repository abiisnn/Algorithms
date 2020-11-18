#include<bits/stdc++.h>
using namespace std;
int main(){
	int range1, range2;
	char digit;

	cin >> range1;
	cin >> range2; 
	cin >> digit;

	long int ans=0;
	for(int i=range1; i<=range2; i++){
		string aux = to_string(i);
		for(int j=0; j<aux.size(); j++){
			if(aux[j] == digit){ 
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}