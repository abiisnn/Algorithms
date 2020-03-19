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
#define MAX 100005
typedef long long int lli;

vector<int> bucket(MAX, 0);
int differentsNumbers() {
	int ans = 0;
	fore(i, 0, MAX) 
		if(bucket[i] > 0) ans++;
	return ans;
}
int deleteElement(int n, int dif) {
	int ihave = bucket[n] - 1;
	int ans = dif;
	if(ihave == 0) {
		ans = dif - 1;
	} 
	return ans;
}
void update(int n) {
	bucket[n]--;
}
int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	vector<int> num(n, 0);
	fore(i, 0, n) {
		cin >> num[i];
		bucket[num[i]]++;
	}
	int differents = differentsNumbers();
	if(differents >= k) {
		int l = 0, r = num.size()-1;
		int auxDif;
		while(r >= l) {
			auxDif = deleteElement(num[r], differents);
			if(auxDif >= k) {
				update(num[r]);
				differents = auxDif;
				r--;
			} else break;
		}
		while(l < r) {
			auxDif = deleteElement(num[l], differents);
			if(auxDif >= k) {
				update(num[l]);
				differents = auxDif;
				l++;
			} else break;
		}
		cout << l+1 << " " << r+1 << endl;
	} else {
		cout << "-1 -1" << endl;
	}

}