#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	lli k;
	int n, numBoxes; cin >> n >> numBoxes >> k;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	int elements = 0, boxes = numBoxes;
	lli actualSize = k, posElem = 0;
	for(int i = 0; i < n; i++) {
		cout << v[i] << " actualSize: " << actualSize << endl;
		cout << "boxes: " << boxes << endl;
		if(v[i] <= actualSize) {
			actualSize -= v[i];
			posElem++;
		} else {
			if(boxes) {
				cout << "entro aqui" << endl;
				elements += posElem;
				actualSize = k;
				boxes--;
			} else {
				elements = 0;
				actualSize = k;
				boxes = numBoxes;
			}
			posElem = 0;
			i--;
		}
		cout << endl;
	}
	elements += posElem;
	cout << elements << endl;


}