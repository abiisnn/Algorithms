void moveZeroes(vector<int>& nums) {
    int current = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        if(nums[i]) {
            nums[current] = nums[i];
            current++;
        }
    }
    for(int i = current; i < int(nums.size()); i++) {
        nums[i] = 0;
    }
}