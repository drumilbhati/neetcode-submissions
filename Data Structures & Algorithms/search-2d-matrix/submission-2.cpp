class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0, hi = n * m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / m;
            int c = mid % m;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return false;
    }
};
