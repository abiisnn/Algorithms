#include<bits/stdc++.h> 
using namespace std;
void goodK(vector<int> &arr, set<pair<int, int>> &good, int condition) {
    for(int i = 0; i < int(arr.size()); i++) {
        for(int j = i + 1; j < int(arr.size()); j++) {
            if(abs(arr[i] - arr[j]) <= condition) {
                good.insert(make_pair(i, j));
            }
        }
    }
}
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    // Generate all possibles combinations
    set<pair<int, int>> I, J;
    goodK(arr, I, c);
    goodK(arr, J, b);
    
    int good = 0;
    for(auto &i: I) {
        for(auto &j: J) {
            if(i.first != j.first && i.second == j.second && (abs(arr[i.first] - arr[j.first]) <= a)){          
                if(i.first < j.first && j.first < i.second) {
                    Triplet valid = {i.first, j.first, i.second};
                    good++;
                }
            }
        }
    }
    return good;
}

int main() {
    int a, b, c, n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> a >> b >> c;
    cout << countGoodTriplets(v, a, b, c) << endl;
}