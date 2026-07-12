#include <bits/stdc++.h>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int dp[101][101];
        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            if (i >= n && j >= m) return 0;
            if (i >= n) {
                return m - j;
            }
            if (j >= m) {
                return n - i;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int res = 0;
            if (word1[i] == word2[j]) {
                res = dfs(dfs, i+1, j+1);
            } else {
                res = 1 + min({
                    dfs(dfs, i+1, j),
                    dfs(dfs, i, j+1),
                    dfs(dfs, i+1, j+1)
                });
            }
            return dp[i][j] = res;
        };

        return dfs(dfs, 0, 0);
    }
};
