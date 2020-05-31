#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;
int main(){
	long long int n,b, c;
	cin >> n;
	if(n%2==0){
		b = (n/2)*(n/2)-1;
		c = (n/2)*(n/2)+1;
	}else{
		b = (n*n-1)/2;
		c = (n*n+1)/2;
	}
	if(n < b && n < c) cout << "Yes, YOU CAN" << endl;
	else cout << "No, please let me go" << endl;
	return 0;
}