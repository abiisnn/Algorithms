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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, index;
	cin >> n;
	vector<lli> nums(n);
	fore(i, 0, n) cin >> nums[i];
	lli lastMax = 10000000000;
	fore(i, 0, n) {
		int j = i-1;
		int der, izq;
		izq = 0;
		while(j>=0) {
			if(nums[j] < nums[i])izq++;
			else break;
			j--;
		}
		j = i+1;
		der = 0;
		while(j < n) {
			if(nums[j] < nums[i]) der++;
			else break;
			j++;
		}
		cout << 1 + izq + der << " ";
	}
	cout << endl;
}