#include<bits/stdc++.h> 
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxN = 0;
    for(int i = 0; i < int(candies.size()); i++) {
        maxN = max(maxN, candies[i]);
    }
    vector<bool> ans(int(candies.size()), false);
    for(int i = 0; i < int(candies.size()); i++) {
        if(candies[i] + extraCandies >= maxN) {
            ans[i] = true;
        }
    }
    return ans;
}