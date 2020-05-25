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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
void printMatrix(vector<vector<int>> m) {
	fore(i, 0, m.size()) {
		fore(j, 0, m[i].size()) {
			cout << m[i][j] << " ";
		} cout << endl;
	}
}
void fillMatrix_4(map<int, int> &bucket, vector<vector<int>> &matrix, vector<int> &nums, int n) {
	int k = 0;
	fore(i, 0, n/2) {
		fore(j, 0, n/2) {
			matrix[i][j] = nums[k];
			matrix[i][n-j-1] = nums[k];
			matrix[n-i-1][j] = nums[k];
			matrix[n-i-1][n-j-1] = nums[k];
			bucket[nums[k]] -= 4;
			k++;
		}
	}
}
void fillMatrix_2(map<int, int> &bucket, vector<vector<int>> &matrix, vector<int> &next, int n) {
	int k = 0;
	fore(i, 0, n/2) {
		matrix[i][n/2] = next[k];
		matrix[n-i-1][n/2] = next[k];
		bucket[next[k]] -= 2;
		k++;
	}
	fore(j, 0, n/2) {
		matrix[n/2][j] = next[k];
		matrix[n/2][n-j-1] = next[k];
		bucket[next[k]] -= 2;
		k++;
	}
}
bool create(map<int, int> &bucket, vector<int>&nums, int k, int need){
	for(auto &i: bucket) {
		fore(j, 0, i.se/k) nums.pb(i.fi);
	}
	if(nums.size() >= need) return true;
	return false;
}
int main() {
	optimizar_io
	int n, k; cin >> n;
	vector<int> v(n*n);
	map<int, int> bucket;
	fore(i, 0, n*n) {
		cin >> v[i];
		bucket[v[i]]++;	
	}
	bool flag = false;
	sort(v.begin(), v.end());
	vector<vector<int>> matrix(n, vector<int>(n));
	if(!(n & 1)) {
		vector<int> nums;
		if(create(bucket, nums, 4, (n/2) * (n/2))) {
			fillMatrix_4(bucket, matrix, nums, n);
			flag = true;
		}
	} else {
		vector<int> nums, next;
		if(create(bucket, nums, 4, (n/2) * (n/2))) {
			fillMatrix_4(bucket, matrix, nums, n);
			if(create(bucket, next, 2, n-1)) {
				fillMatrix_2(bucket, matrix, next, n);
				for(auto &i: bucket) {
					if(i.se) {
						matrix[(n/2)][(n/2)] = i.fi;
						break;
					}
				}
				flag = true;
			}
		}
	}
	if(flag) {
		cout << "YES" << endl;
		printMatrix(matrix);
	} else cout << "NO" << endl;
}