class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);

        vector<int> dp(5001);
        dp[0] = 1;

        sort(nums.begin(), nums.end());

        for (int x: nums) {
            for (int i=5000; i>=x; i--) {
                if (dp[i-x]) {
                    dp[i] += dp[i-x];
                }
            }
        }

        return (sm % 2 == 0 && dp[sm / 2]);
    }
};
