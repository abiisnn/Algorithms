/*
    [4, 3, 2, -1, -2, -3] 
                   ^
    v[mid] > 0:
        l = mid + 1
    v[mid] < 0
    return grid[i].size()
 */
int firstNegative(vector<int> &gridI) {
    int l = 0, r = gridI.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(gridI[mid] >= 0) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int countNegatives(vector<vector<int>>& grid) {
    int negatives = 0;
    for(int i = 0; i < (int)grid.size(); i++) {
        // Find first negative number
        int index = firstNegative(grid[i]);
        negatives += (grid[i].size() - index);
    }
    return negatives;
}