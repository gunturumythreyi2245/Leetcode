class NumMatrix {
private:
    vector<vector<int>> pref;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pref = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i + 1][j + 1] = matrix[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
    }
};