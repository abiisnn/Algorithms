/*
-> Brute force solution:
    array = [1,2,3,1,1,3] O(n * n) n: size of the array
-> Best solution
    1. Using a map like a bucket, where a bucket tell us the number of times a number ocurrs
    in the array.
    2. Iterate from 0-n
        remove the number from the bucket.
        total = total + (bucket[i])
*/
int numIdenticalPairs(vector<int>& nums) {
    map<int, int> bucket;
    for(int i = 0; i < int(nums.size()); i++) {
        bucket[nums[i]]++;
    }
    int good = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        bucket[nums[i]]--;
        good +=  bucket[nums[i]]; 
    }
    return good;
}