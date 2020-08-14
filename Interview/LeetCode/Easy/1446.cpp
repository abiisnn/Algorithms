int maxPower(string s) {
    char last = '#';
    int cont = 0, bestAns = 0;
    for(int i = 0; i < int(s.size()); i++) {
        if(s[i] == last) {
            cont++;
        } else {
            bestAns = std::max(bestAns, cont);
            cont = 1;
        }
        last = s[i];
    }
    bestAns = std::max(bestAns, cont);
    return bestAns;
}