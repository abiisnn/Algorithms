#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 105
typedef long long int lli;
char matrix[MAX][MAX];

void clearMatrix() {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			matrix[i][j] = '.';
		}
	}
}

void update(int a, int b, int c, int d, char color) {
	for(int i = a; i <= c; i++) {
		for(int j = b; j <= d; j++) {
			matrix[i][j] = color;
		}
	}
}
int main() {
	optimizar_io
	int N, R, C, I, a, b, c, d;
	char color;
	cin >> N;
	while(N--) {
		cin >> R >> C >> I;
		clearMatrix();
		for(int i = 0; i < I; i++) {
			cin >> a >> b >> c >> d >> color;
			update(a, b, c, d, color);			
		}
		for(int i = 1; i <= R; i++) {
			for(int j = 1; j <= C; j++) {
				cout << matrix[i][j];
			} cout << endl;
		}
	}
}