int firstUniqChar(string s) {
    vector<int> bucket(27);
    
    for(int i = 0; i < int(s.size()); i++) {
        bucket[s[i]-'a']++;
    }
    int index = -1;
    for(int i = 0; i < int(s.size()); i++) {
        if(bucket[s[i]-'a'] == 1) {
            index = i;
            break;
        }
    }
    return index;
}