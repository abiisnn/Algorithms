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
#define MOD 1000000007
#define INF 500000
#define MAX 1000000
#define MIN -1
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int diff(int r, int g, int b, int y) {
	int ma = max(r, max(g, max(b, y)));
	int mi = min(r, min(g, min(b, y)));
	return ma - mi;
}
int main() {
	optimizar_io
	string pat; cin >> pat;
	int best = MAX, l = 0, rlim = 0;
	
	vector<int> bucket(27);
	vector<vector<int>> v(pat.size(), vector<int>(4));
	
	int R = 0, G = 0, B = 0, Y = 0;
	fore(i, 0, pat.size()) {
		if(pat[i] == 'R') R++;
		else if(pat[i] == 'G') G++;
		else if(pat[i] == 'B') B++;
		else Y++;
		v[i][0] = R;
		v[i][1] = G;
		v[i][2] = B;
		v[i][3] = Y;
	}
	fore(i, 0, pat.size()) {
		fore(j, i, pat.size()) {
			int r = v[j][0], g = v[j][1], b = v[j][2], y = v[j][3];
			if(i) {
				r -= v[i-1][0], g -= v[i-1][1];
				b -= v[i-1][2], y -= v[i-1][3];
			}
			int aqui = diff(r, g, b, y);
			if(aqui == best && (j - i) > (rlim - l)) {
				l = i, rlim = j;
			} else if(aqui < best) {
				best = aqui;
				l = i, rlim = j;
			}
		}
	}
	cout << best << " " << rlim - l + 1 << endl;
	cout << l+1 << " " << rlim+1 << endl;
}