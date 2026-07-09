class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(n * m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                v[i*m+j] = matrix[i][j];
            }
        }

        int lo = 0, hi = n * m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (v[mid] == target) {
                return true;
            } else if (v[mid] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return false;
    }
};
