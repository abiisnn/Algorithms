#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define N 100002
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli mem[2][N];
lli numbers[2][N];

lli dp(int i, int j, int &n) {
	if((i < 0) or (i >= 2) ) return 0;
	if((j < 0) or (j >= n)) return 0;
	if(mem[i][j] != -1) return mem[i][j];
 
	lli take = 0;
	// TAKE
	if(i == 0) take = numbers[i][j] + dp(i+1, j+1, n);
	else take = numbers[i][j] + dp(i-1, j+1, n); 
	lli noTake = dp(i, j+1, n);
	return mem[i][j] = max(take, noTake);
}
void clearMem() {
	fore(i, 0, 2) {
		fore(j, 0, N) mem[i][j] = -1;
	}
}
int main() {
	cin.tie(0);
	int n;
	lli result;
	cin >> n;
 
	clearMem();
	fore(i, 0, 2) {
		fore(j, 0, n) cin >> numbers[i][j];
	}
	result = dp(0, 0, n);
	result = max(result, dp(1, 0, n));
	cout << result << endl;

}