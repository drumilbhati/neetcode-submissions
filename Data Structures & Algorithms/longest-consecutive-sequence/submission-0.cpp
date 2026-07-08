class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> dp;
        int mx = 0;
        for (int i=0; i<n; i++) {
            if (dp.count(nums[i]-1)) {
                dp[nums[i]] = max(dp[nums[i]], dp[nums[i]-1] + 1);
            } else {
                dp[nums[i]] = 1;
            }
            mx = max(mx, dp[nums[i]]);
        }
        return mx;
    }
};
