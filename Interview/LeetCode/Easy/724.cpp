#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) { 
    int sumL = 0, sumR = 0;
    for(int i = 1; i < (int)nums.size(); i++) {
        sumR += nums[i];
    }
    int pivot = -1;
    for(int i = 0; i < (int)nums.size()-1; i++) {
        if(sumL == sumR) {
            pivot = i;
            break;
        }
        sumL += nums[i];
        sumR -= nums[i+1];
    }
    if(!sumL && pivot == -1) {
        pivot = nums.size() - 1;
    }
    return pivot;
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i= 0; i < n; i++) cin >> v[i];

    cout << "pivot: " << pivotIndex(v) << endl;
}