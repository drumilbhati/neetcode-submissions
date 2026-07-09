class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        auto solve = [&](char c) -> int {
            int res = 0;
            int l=0, r=0;

            int op = 0;
            for (; r<n; r++) {
                if (s[r] != c) {
                    op++;
                }
                while (l < r && op > k) {
                    if (s[l] != c) {
                        op--;
                    }
                    l++;
                }

                res = max(res, r - l + 1);
            }
            return res;
        };


        for (char c='A'; c<='Z'; c++) {
            ans = max(ans, solve(c));
        }

        return ans;
    }
};
