int numJewelsInStones(string J, string S) {
    set<char> stones;
    for(int i = 0; i < int(J.size()); i++) {
        stones.insert(J[i]);
    }
    int total = 0;
    for(int i = 0; i < int(S.size()); i++) {
        if(stones.count(S[i])) {
            total++;
        }
    }
    return total;
}