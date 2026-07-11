class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        for (int i=1; i<n; i++) {
            dp[i][0] = min({nums[i], nums[i] * dp[i-1][0], nums[i] * dp[i-1][1]});
            dp[i][1] = max({nums[i], nums[i] * dp[i-1][0], nums[i] * dp[i-1][1]});
        }
        
        int ans = INT_MIN;
        for (int i=0; i<n; i++) {
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};
