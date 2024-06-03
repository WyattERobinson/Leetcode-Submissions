class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) { return {}; }

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> diagonals(m + n - 1);
        vector<int> result;

        // Categorize each diagonal into another arr
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 0) {
                    diagonals[i + j].insert(diagonals[i + j].begin(), mat[i][j]);
                }
                else {
                    diagonals[i + j].push_back(mat[i][j]);
                }
            }
        }

        // Flatten diagonal arr into result
        for (const vector<int> diagonal : diagonals) {
            result.insert(result.end(), diagonal.begin(), diagonal.end());
        }

        return result;
    }
};