class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (m < n) return false;

        map<char, int> mp, mp1;
        
        for (int i=0; i<n; i++) {
            mp[s1[i]]++;
        }

        for (int i=0; i<m; i++) {
            mp1[s2[i]]++;

            if (i >= n) {
                mp1[s2[i-n]]--;
                if (mp1[s2[i-n]] == 0) {
                    mp1.erase(s2[i-n]);
                }
            }

            if (i >= n-1) {
                if (mp == mp1) return true;
            }
        }
        return false;
    }
};
