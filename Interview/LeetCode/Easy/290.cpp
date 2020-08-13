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
        } else {
            word += str[i];
        }        
    }
    if(word.size() > 0) {
        split.push_back(word);
    }
    
    if(split.size() != pattern.size()) {
        return false;
    }
    map<char, string> bucket;
    set<string> values;
    bool flag = true;
    for(int i = 0; i < int(pattern.size()); i++) {
        string actual = bucket[pattern[i]];
        if(actual.size() > 0) {
            if(split[i] != actual) {
                flag = false;
                break;
            } 
        }
        else {
            if(values.count(split[i])) {
                flag = false;
                break;
            }
            bucket[pattern[i]] = split[i];
            values.insert(split[i]);
        }
    }
    return flag;
}
int main() {
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    cout << a << endl;
    cout << b << endl;
    cout << wordPattern(a, b) << endl;
}