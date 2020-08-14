int findMaxConsecutiveOnes(vector<int>& nums) {
    int bestAns = 0, last = 0, cont = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        if(nums[i] == last) {
            cont++;
        } else {
            if(last) {
                bestAns = std::max(bestAns, cont);
            }
            cont = 1;
        }
        last = nums[i];
    }
    if(last) {
        bestAns = std::max(bestAns, cont);
    }
    return bestAns;
}