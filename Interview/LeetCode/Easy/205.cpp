bool isIsomorphic(string s, string t) {
    map<char, char> bucket;
    set<char> values;
    bool flag = true;
    for(int i = 0; i < int(s.size()); i++) {
        char actual = bucket[s[i]];
        if(actual) {
            if(t[i] != actual) {
                flag = false;
                break;
            }
        } else {
            if(values.count(t[i])) {
                flag = false;
                break;
            }
            bucket[s[i]] = t[i];
            values.insert(t[i]);
        }
    }
    return flag;
}