#include<bits/stdc++.h>
using namespace std;

int find(vector<pair<int, int>> &v, int target) {
        int sz = v.size();
        int l = 0, r = sz - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(v[m].first < target) l = m + 1;
            else if(v[m].first > target) r = m - 1;
            else r = m - 1;
        }
        if(l < sz && v[l].first == target) {
            return l;
        }
        return sz;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
        vector<pair<int, int>> v(nums.size(), pair<int,int>());
        for(int i = 0; i < nums.size(); i++) {
            v[i] = make_pair(nums[i], i);
            freq[nums[i]]++;
        }
        sort(v.begin(), v.end());

        bool flag = false;
        int a = -1, b = nums.size(), sz = nums.size();
        for(int i = 0; i < sz; i++) {
            int need = target - v[i].first;
            int f = freq[need];
            int index = find(v, need);
            if(index != sz) {
                if(need == v[i].first) {
                    if(f >= 2) {
                    	a = v[i].second; index++;
                        b = v[index].second;
                        flag = true;
                        break;              		
                    } else continue;
                }
                a = v[i].second;
                b = v[index].second;
                flag = true;
                break;
            }
        }
        if(flag) return {a, b};
        return {-1, -1};
    }

int main() {
	int n, target; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cin >> target;

	vector<int> ans = twoSum(nums, target);
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
}