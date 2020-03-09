#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string str) {
    vector<string> split;
    // Split str
    string word = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            split.push_back(word);
            word = "";                
        }
        else {
            word += str[i];            
        }
    }
    if(word.size() > 0) {
        split.push_back(word);
    }

    if(split.size() != pattern.size()) {
        return false;
    }       
    vector<int> bucket(26, 0);
    map<char, string> m;
    for(int i = 0; i < pattern.size(); i++) {
        bucket[pattern[i] - 'a']++;
        if(bucket[pattern[i] - 'a'] == 1) {
            m[pattern[i]] = split[i];
        }
    }
    for(auto &i: m) {
        cout << i.first << " " << i.second << endl;
    } cout << endl;
    
    bool ans = true;
    for(int i = 0; i < pattern.size(); i++) {
        if(m[pattern[i]] != split[i]) {
            ans = false;
        }
    }
    return ans;
}
int main() {
    string s, p;
    getline(cin, p);
    getline(cin, s);
    cout << wordPattern(p, s) << endl;
}
