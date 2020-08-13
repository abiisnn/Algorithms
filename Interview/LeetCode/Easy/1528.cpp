string restoreString(string s, vector<int>& indices) {
    string ans(int(s.size()), ' ');
    for(int i = 0; i < int(s.size()); i++) {
        ans[indices[i]] = s[i];    
    }
    return ans;
}