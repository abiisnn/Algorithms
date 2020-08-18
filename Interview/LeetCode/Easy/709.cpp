string toLowerCase(string str) {
    string ans = "";
    for(int i = 0; i < int(str.size()); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') ans += char(str[i] + 32);
        else ans += str[i];
    }
    return ans;
}