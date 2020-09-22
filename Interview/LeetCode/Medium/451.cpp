string frequencySort(string s) {
    map<char, int> bucket;
    for(int i = 0; i < int(s.size()); i++) {
        bucket[s[i]]++;
    }
    priority_queue<pair<int, char>> heap;
    
    for(auto &i: bucket) {
        heap.push(make_pair(i.second, i.first));
    }
    string sorted = "";
    while(!heap.empty()) {
        pair<int, char> element = heap.top();
        heap.pop();
        while(element.first--) {
            sorted += element.second;
        }
    }
    return sorted;
}