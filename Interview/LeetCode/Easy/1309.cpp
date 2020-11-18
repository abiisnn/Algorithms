#include<bits/stdc++.h>
using namespace std;
 /*
    -> How to split the string
        - Number between 1-9 : 1, 2
        - Number between 10-26: 10, 11, 20, 21
    Iterate string S, 
    if(s[i] == '1' or '2')
*/
void createMap(map<string, string> &mapping) {
    for(int i = 1; i <= 9; i++) {
        string key = to_string(i), value(1, 'a' + i - 1);
        mapping[key] = value;
    }
    for(int i = 10; i <= 26; i++) {
        string key = to_string(i) + "#", value(1, 'j' + i - 10);
        mapping[key] = value;
    }
}
string freqAlphabets(string s) {
    map<string, string> mapping;
    createMap(mapping); 
    int i = 0; 
    string decrypt = "", val; // DECRYPT = VAL
    while(i < s.size()-2) {
        if(s[i+2] == '#') {
            val = s.substr(i, 3);
            i += 3;
        } else {
            val = s.substr(i, 1);
            i++;
        }
        decrypt += mapping[val];
    }
    if(s[s.size()-1] != '#') {
        if(s.size() >= 2) decrypt += mapping[s.substr(s.size()-2, 1)];
        decrypt += mapping[s.substr(s.size()-1, 1)];
    }
    return decrypt;
}
int main() {
    string s;
    cin >> s;
    cout << freqAlphabets(s) << endl;
}