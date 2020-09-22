int singleNumber(vector<int>& nums) {
    map<int, int> freq;
    for(int i = 0; i < (int)nums.size(); i++) {
        freq[nums[i]]++;
    }
    int single = 0;
    for(auto &i: freq) {
        if(i.second == 1) {
            single = i.first;
        }
    }
    return single;
}

int singleNumber(vector<int>& nums) {
    int single = 0;
    for(int i = sizeof(single) * 8 - 1; i >= 0; i--) {
        int times = 0;
        for(int j = 0; j < (int)nums.size(); j++) {
            if((nums[j] >> i) & 1) {
              times++;  
            }
        }
        if(times % 3) {
            single += (1 << i);
        }
    }
    return single;
}