class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int ans = 0;

        for (int i=0; i<n; i++) {
            ans++;
            int l=i-1, r=i+1;
            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            l=i-1, r=i;
            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
