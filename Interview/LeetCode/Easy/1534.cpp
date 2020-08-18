#include<bits/stdc++.h> 
using namespace std;
void goodK(vector<int> &arr, set<pair<int, int>> &good, int condition) {
    // I = [0,]
    // [3,0,1,1,9,7], condition = 3
    for(int i = 0; i < int(arr.size()); i++) {
        for(int j = i + 1; j < int(arr.size()); j++) {
            // (i or j) and k
            // a[i] = 3, a[j] = 1
            if(abs(arr[i] - arr[j]) <= condition) {
                good.insert(make_pair(i, j));
            }
        }
    }
}
// [3,0,1,1,9,7]
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    // Generate all possibles combinations
    set<pair<int, int>> I, J;
    goodK(arr, I, c); // {0, }
    goodK(arr, J, b);
    
    int totalGoods = 0;
    for(auto &i: I) {
        for(auto &j: J) {
            |
        }
    }
    return totalGoods / 2;
}

int main() {
    int a, b, c, n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> a >> b >> c;
    cout << countGoodTriplets(v, a, b, c) << endl;
}