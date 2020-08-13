int maxProduct(vector<int>& nums) {
    int a = 0, freqa = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        a = std::max(nums[i], a);
    }
    for(int i = 0; i < int(nums.size()); i++) {
        if(nums[i] == a) {
            freqa++;
        }
    }
    if(freqa >= 2) {
        return (a - 1) * (a - 1);
    }
    int b = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        if(nums[i] > b && nums[i] != a) {
            b = nums[i];
        }
    }
    return (a - 1) * (b - 1);
}