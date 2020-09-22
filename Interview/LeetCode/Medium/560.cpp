// Time: O(n^2), Space = O(n)
int subarraySum(vector<int>& nums, int k) {
    vector<int>acum(nums.size()+1);
    for(int i = 1; i <(int)acum.size(); i++) {
        acum[i] = nums[i-1] + acum[i-1];  
    }
    int cont = 0;
    for(int i = 0; i < (int)nums.size(); i++) {
        for(int j = i; j < (int)nums.size(); j++) {
            // [i, j] -> acum[j+1] - acum[i]
            if(acum[j+1] - acum[i] == k) {
                cont++;
            }
        }
    }
    return cont;
}
int subarraySum(vector<int>& nums, int k) {
    vector<int>acum(nums.size()+1);
    map<int, int> sums;
    for(int i = 1; i <(int)acum.size(); i++) {
        acum[i] = nums[i-1] + acum[i-1];
        sums[acum[i]]++;
    }
    int cont = 0;
    for(int i = (int)acum.size()-1; i >= 1; i--) {
        sums[acum[i]]--;
        int need = acum[i] - k;
        cont += sums[need];
        if(acum[i] == k) cont++;
    }
    return cont;
}

// time: O(nlogn) space: O(n)
int subarraySum(vector<int>& nums, int k) {
    map<int, int> sums;
    int currentSum = 0;
    for(int i = 0; i < (int)nums.size(); i++) {
        currentSum += nums[i];
        sums[currentSum]++; 
    }
    int cont = 0;
    for(int i = (int)nums.size()-1; i >= 0; i--) {
        sums[currentSum]--;
        int need = currentSum - k;
        cont += sums[need];
        if(currentSum == k) cont++;
        currentSum -= nums[i];
    }
    return cont;
}