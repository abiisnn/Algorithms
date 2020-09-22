string saveAns(int begin, int end) {
    string a = to_string(begin);
    string b = to_string(end);
    if(begin != end) {
        a += "->" + b;
    }
    return a;
}
vector<string> summaryRanges(vector<int>& nums) {
    if(!int(nums.size())) return {};
   
    vector<string> summary;
    long int last = nums[0];
    int begin = nums[0];
    for(int i = 1; i < int(nums.size()); i++) {
        if(abs(last - nums[i]) != 1) {
            string element = saveAns(begin, last);
            summary.push_back(element);
            begin = nums[i];
        }
        last = nums[i];
    }
    string element = saveAns(begin, last);
    if(int(element.size())) summary.push_back(element);
    
    return summary;
}