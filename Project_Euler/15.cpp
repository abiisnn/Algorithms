// https://www.robertdickau.com/lattices.html
#include<bits/stdc++.h>
#define N 20
using namespace std;
typedef long long int lli;

int main() {
	lli n = 20;
	lli gauss = (n * (n+1)) / 2;
	cout << "gauss: " << gauss << endl;
	lli ans = (n) * gauss;
	cout << ans << endl;
}
