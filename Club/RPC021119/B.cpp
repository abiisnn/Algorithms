#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

int main() {
	string srt, aux = "";
	int i, bar = 0, x = 0, sum = 0, res = 0;

	while(cin >> srt) {
		if(srt[0] == 124) bar += srt.size();
		else {
			for(i = 0; i < srt.size(); i++){
				if(srt[i] == ',') break;
				aux += srt[i];
			}
			stringstream num(aux);  
		    num >> x; 
		    res = srt.size() - i - 2;
		    if(res) sum += (res * x);
		    else sum += x;
		}			
	}
	sum += (bar * 42);
	while((sum % 10) != 0) {
		sum++;
	}
	cout << sum << ",-";
}