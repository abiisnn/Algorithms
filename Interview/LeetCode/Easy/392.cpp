bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while(i < int(s.size()) && j < int(t.size())) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }
    if(i == int(s.size())) return true;
    return false;
}