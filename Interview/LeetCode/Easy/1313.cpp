/*
    Create a vector that will be the answer
    -> Declare in the beginning, indicate the size:
        I have to iterate through the array and calculate the size of the answer
    -> Using push_back method of the vector in c++, we can create the answer when we
        iterate the vector nums.
*/
vector<int> decompressRLElist(vector<int>& nums) {
    int size = 0;
    // [1,2,3,4]
    for(int i = 0; i < nums.size(); i+=2) {
        size += nums[i]; // size = 4
    }
    vector<int> decompress(size);
    // [2,4,4,4]
    int k = 0;
    for(int i = 0; i < nums.size(); i+=2) {
        for(int j = 0; j < nums[i]; j++) { // 3
            decompress[k] = nums[i+1]; // k =3, 4
            k++;
        }
    }
    return decompress;
}