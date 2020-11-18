string getMorse(vector<string> &morse, string word) {
    string transformed = "";
    for(int i = 0; i < int(word.size()); i++) {
        transformed += morse[word[i]-'a'];
    }
    return transformed;
}
int uniqueMorseRepresentations(vector<string>& words) {
    set<string> transformation;
   vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(int i = 0; i < int(words.size()); i++) {
        string trans = getMorse(morse, words[i]);
        transformation.insert(trans);
    }
    return int(transformation.size());
}