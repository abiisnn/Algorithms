int removeDuplicates(vector<int>& nums) {
    if(!int(nums.size())) return 0;
    int last = nums[0], current = 0;
    for(int i = 1; i < int(nums.size()); i++) {
        if(nums[i] != last) {
            nums[current] = last;
            current++;
        }
        last = nums[i];
    }
    nums[current] = last;
    current++;
    return current;
}