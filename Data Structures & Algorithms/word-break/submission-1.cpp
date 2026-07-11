#include <bits/stdc++.h>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        set<string> st(wordDict.begin(), wordDict.end());
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto&& dfs, int l, int r) -> int {
            if (l == n) return 1;    
            if (r > n) return 0;

            if (dp[l][r] != -1) return dp[l][r];

            int res = 0;
            if (st.count(s.substr(l, r-l+1))) {
                res = res || dfs(dfs, r+1, r+1);
            }
            res = res || dfs(dfs, l, r+1);

            return dp[l][r] = res;
        };

        return dfs(dfs, 0, 0);
    }
};
