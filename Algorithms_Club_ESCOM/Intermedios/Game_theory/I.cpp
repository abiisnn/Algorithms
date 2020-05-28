/* Ada and Easy Game
   Tengo n pilas y M cantidades disponibles 
*/
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
typedef long long int lli;

int MEX(set<int> st) { // O(|st| * log(|st|))
	for(int i = 0;; i++) {
		if(!st.count(i))
			return i;
	}
}

int main() {

}