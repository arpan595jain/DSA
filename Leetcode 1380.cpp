class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxCols[50] = {};
        vector<int> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                maxCols[i] = max(maxCols[i], matrix[j][i]);
        for (int i = 0; i < m; i++){
            int minRow = matrix[i][0], colIndex = 0;
            for (int j = 1; j < n; j++)
                if (matrix[i][j] < minRow){
                    minRow = matrix[i][j];
                    colIndex = j;
                }
            if (minRow == maxCols[colIndex])
                res.push_back(minRow);
        }
        return res;
    }
};
