int balancedStringSplit(string s) {
    int R = 0, L = 0, i = 0, ans = 0;
    while(i < int(s.size())) {
        if(s[i] == 'R') R++;
        if(s[i] == 'L') L++;
        if(R == L) {
            ans++;
            R = 0; 
            L = 0;
        }
        i++;
    }
    return ans;
}