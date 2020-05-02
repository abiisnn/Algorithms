#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
void printBits(int n) {
	for (int i = sizeof(n) * 8 - 1; ~i; i--)
		cout << ((n >> i) & 1);
	cout << endl;
}
lli msb(lli n) { 
    if (n == 0) 
        return 0;
    lli msb = 0; 
    while (n != 0) { 
        n = n / 2; 
        msb++; 
    } 
    return (1 << msb); 
} 
lli lsb(lli n) { return n & -n; }
int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<lli> nums(n);
	lli gre = -1;
	fore(i, 0, n) {
		cin >> nums[i];
		// cout << nums[i] << endl;
		// printBits(nums[i]);
		// cout << "msb: " << msb(nums[i]) << endl;
		if(nums[i] > gre){
			gre = nums[i];
		}
	}
	lli ans = 0;
	fore(i, 0, n) {
		lli a = 2 ^nums[i];
		cout << 2 << " " <<nums[i] << " :" << a <<endl;
 		if((gre^nums[i]) >ans) ans = gre ^nums[i];
	}
	cout << ans << endl;
}