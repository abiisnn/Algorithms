#include<bits/stdc++.h>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> bucket(101), acum(101), ans(int(nums.size()));
    for(int i = 0; i < int(nums.size()); i++) {
        bucket[nums[i]]++;
    }
    acum[0] = bucket[0];
    for(int i = 1; i < 101; i++) {
        acum[i] = acum[i-1] + bucket[i];
    }
    for(int i = 0; i < 101; i++) {
        acum[i] -= bucket[i];
    }        
    for(int i = 0; i < int(nums.size()); i++) {
        ans[i] = acum[nums[i]];
    }
    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans = smallerNumbersThanCurrent(v);
}