#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
int change(map<int, int> &m, int dif, int n) {
	int actual = m[n];
	if(actual == 0) {
		return dif+1;
	}
	return dif;
}
int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	vector<int> nums(n), acum(n);
	map<int, int> m;
	fore(i, 0, n)  {
		cin >> nums[i];
	}
	int i = 0, j = 0;
	int dif = 1;
	m[nums[0]]++;
	while(i < n && j < n) {
		cout << i << " " << j << endl;
		int aux = change(m, dif, nums[j+1]);
		cout << "tendria: " << aux << endl;
		if(aux <= k) {
			cout << "j camina" << endl;
			j++;
			m[nums[j+1]]++;
			dif = m.size();
		} else break;
		// else if(m[nums[i]] == 1) {
		// 	i++; j++;
		// 	m[nums[i]]--;
		// } else break;
	}

	cout << i << " " << j << endl;

}