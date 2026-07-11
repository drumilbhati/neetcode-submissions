#include <bits/stdc++.h>
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp[101];
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto&& dfs, int i) -> int {
            if (i == n) return 1;
            if (i > n) return 0;

            if (dp[i] != -1) return dp[i];

            int res = 0;
            if (s[i] != '0') {
                res += dfs(dfs, i+1);
            }
            if (s[i] == '1') {
                res += dfs(dfs, i+2);
            }
            if (i < n-1 && s[i] == '2' && s[i+1] <= '6') {
                res += dfs(dfs, i+2);
            } 

            return dp[i] = res;
        };

        return dfs(dfs, 0);
    }
};
