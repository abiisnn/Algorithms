#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define pairs pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define N 3
typedef long long int lli;

int in[N][N];
int out[N][N];

void update(int number, int i, int j) {
	vector<pairs> mov = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	for(auto &p: mov) {
		int x = p.fi + i;
		int y = p.se + j;
		if((x < N) && (x >= 0) && (y < N) && (y >= 0)) {
			out[x][y] += number;
		}
	}
}
int main() {	
	fore(i, 0, 3) {
		fore(j, 0, 3) {
			out[i][j] = 0;
		}
	}
	fore(i, 0, 3) {
		fore(j, 0, 3) {
			cin >> in[i][j];
			out[i][j] += in[i][j];
			update(in[i][j], i , j);
		}
	}


	fore(i, 0, 3) {
		fore(j, 0, 3) {
			if(out[i][j] & 1) {
				cout << "0";
			}
			else cout << "1";
		} cout << endl;
	}

}