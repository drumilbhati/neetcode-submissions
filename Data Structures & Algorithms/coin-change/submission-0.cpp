class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int, int> dp;
        for (int coin: coins) {
            dp[coin] = 1;
        }

        for (int i=1; i<=amount; i++) {
            if (!dp.count(i)) dp[i] = INT_MAX;
            for (int coin: coins) {
                if (i >= coin && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};
