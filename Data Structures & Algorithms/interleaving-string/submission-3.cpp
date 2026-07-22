#include <bits/stdc++.h>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int sz = s3.size();

        if (n + m != sz) return false;

        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto&& dfs, int i, int j) -> bool {
            if (i == n && j == m) return 1;
            
            if (dp[i][j] != -1) return dp[i][j];
            
            int k = i + j;

            int res = 0;
            if (i < n && k < sz && s1[i] == s3[k]) {
                res = res || dfs(dfs, i+1, j);
            }
            if (j < m && k < sz && s2[j] == s3[k]) {
                res = res || dfs(dfs, i, j+1);
            }
            return dp[i][j] = res;
        };

        return dfs(dfs, 0, 0);
    }
};
