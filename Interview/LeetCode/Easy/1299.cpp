vector<int> replaceElements(vector<int>& arr) {        
    int greater = arr[(int)arr.size()-1];
    
    vector<int> replaced((int)arr.size());
    replaced[(int)arr.size()-1] = -1;
    
    for(int i = (int)arr.size()-2; i >= 0; i--) {
        replaced[i] = greater;
        greater = std::max(greater, arr[i]);
    }
    return replaced;
}