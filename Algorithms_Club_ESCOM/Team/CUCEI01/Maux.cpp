#include <iostream>
#include <cmath>
using namespace std;
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

	cout << "b:"<<b << endl;
	cout << "c:"<<c << endl;

	cout << "a^2+b^2: "<<((n*n) + (b*b)) << endl;
	cout << "c^2:     " << (c*c);
	return 0;
}