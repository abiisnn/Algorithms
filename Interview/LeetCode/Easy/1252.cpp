// Time: (n * m) Space: (n + m)
int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<int> row(n), col(m);
    for(int i = 0; i < int(indices.size()); i++) {
        row[indices[i][0]]++;
        col[indices[i][1]]++;
    }
    int odd = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((row[i] + col[j]) & 1) {
                odd++;
            }
        }
    }
    return odd;
}