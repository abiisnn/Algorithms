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
    int l = 0, r = 0, sizeMap = 1, greater = 1;
    bucket[s[0]]++;
    while(l < int(s.size()) && r < int(s.size())) {
        cout << "sizeMap: " << sizeMap << " elements: " << r-l+1 << endl;
        if(sizeMap == r - l + 1) { // 2 == 1
            r++; // r = 1
            cout << "Agrego: " << s[r] << endl;
            insertElement(bucket, sizeMap, s[r]); // sizeMap = 1 
            greater = std::max(greater, sizeMap); // greater = 1
        } else {
            cout << "Elimino: " << s[l] << endl;
            deleteElement(bucket, sizeMap, s[l]);
            l++;
        }
    }
    return greater;
}

int main() {
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
}