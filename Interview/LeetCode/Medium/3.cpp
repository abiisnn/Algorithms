#include<bits/stdc++.h>
using namespace std;
void insertElement(map<char, int> &bucket, int &sizeMap, char c) {
    int current = bucket[c];
    if(current == 0) sizeMap++;
    bucket[c]++;
}
void deleteElement(map<char, int> &bucket, int &sizeMap, char c) {
    int current = bucket[c];
    if(current - 1 == 0) sizeMap--;
    bucket[c]--;
}
int lengthOfLongestSubstring(string s) {
    map<char, int> bucket;
    int l = 0, r = 0, sizeMap = 0, greater = 0;
    
    while(l < int(s.size()) && r < int(s.size())) {
        if(sizeMap == r - l) { // 2 == 1
            insertElement(bucket, sizeMap, s[r]); // sizeMap = 1 
            greater = std::max(greater, sizeMap); // greater = 1
            r++; // r = 1
        } else {
            deleteElement(bucket, sizeMap, s[l]);
            l++;
        }
    }
    return greater;
}
// Better option
int lengthOfLongestSubstring(string s) {
        set<char> exist;
        int l = 0, r = 0, greater = 0; 
        while(l < int(s.size()) && r < int(s.size())) {
            if(!exist.count(s[r])) { // 2 == 1
                exist.insert(s[r]);
                greater = std::max(greater, r - l + 1); // greater = 1
                r++;
            } else {
                exist.erase(s[l]);
                l++;
            }
        }
        return greater;
    }
int main() {
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
}