class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i=0; i<n; i++) {
            string res = "";
            res += s[i];
            int l=i-1, r=i+1;

            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    res = s[l] + res + s[r];
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            if (ans.size() < res.size()) {
                ans = res;
            }

            res = "";
            l=i-1, r=i;

            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    res = s[l] + res + s[r];
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            if (ans.size() < res.size()) {
                ans = res;
            }
        }
        return ans;
    }
};
