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
#define MAX 1000005
#define Nmax 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> nums(Nmax);
vector<vector<int>> matrix(Nmax, vector<int>(0));
bool dfs(int from, int to, vector<bool> &visited, int &greater, int &mini) {
	// cout << "from: " << from << " to: " << to << endl;
	// cout << "greater: " << greater << " min: " << mini << endl;
	int flag = 0;
	if (from == to) {
		// cout << "nums en from: " << nums[from] << endl; 
		if(nums[from] > greater) greater = nums[from];
		if(nums[from] < mini) mini = nums[from];
		return true;
	}
	if(visited[from]) {
		return false;
		
	}
	if(!visited[from])
		visited[from] = true;
	for (int i = 0; i < matrix[from].size(); i++) {
		bool ans = dfs(matrix[from][i], to, visited, greater, mini);
		if (ans) {
			// cout << "Estoy en: " << from << " ----> altitud: " << nums[matrix[from][i]] << endl; 
			if(nums[matrix[from][i]] > greater) greater = nums[matrix[from][i]];
			if(nums[matrix[from][i]] < mini) mini = nums[matrix[from][i]];
			// cout << "greater: " << greater << " min: " << mini << endl;
			return true;
		}
	}
	return false;

}
int main() {
	int N, a, b, q;
	cin >> N;
	fore(i, 0, N) cin >> nums[i];
	fore(i, 0, N-1) {
		cin >> a >> b;
		matrix[a-1].pb(b-1);
		matrix[b-1].pb(a-1);
	}
	cin >> q;
	while(q--) {
		cin >> a >> b;
		int greater = 0, mini = MAX;
		vector<bool> visited(N, false);
		// cout << "Voy de: " << a << " a: " << b << endl;
		if(dfs(a-1, b-1, visited, greater, mini)) {
			if(nums[a-1] > greater) greater = nums[a-1];
			if(nums[a-1] < mini) mini= nums[a-1];
			// cout << "greater: " << greater << " min: " << mini << endl;
			cout << greater - mini << endl;
		} else cout << 0 << endl;
	}


}