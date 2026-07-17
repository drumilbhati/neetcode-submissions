class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto& x, auto& y) {
            return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1];
        });
        vector<vector<int>> ans(k);
        for (int i=0; i<k; i++) {
            ans[i] = points[i];
        }
        return ans;
    }
};
