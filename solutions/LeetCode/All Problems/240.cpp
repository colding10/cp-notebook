#include <algorithm>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = matrix.size();
        for (int i = 0; i < l; i++) {
            if (std::binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                return true;
            }
        }
        return false;
    }
}
