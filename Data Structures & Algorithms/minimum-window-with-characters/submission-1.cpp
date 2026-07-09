class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp, mp1;

        for (char c: t) {
            mp[c]++;
        }

        int have = 0, need = mp.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0, r = 0;
        for (; r < s.size(); r++) {
            char c = s[r];
            mp1[c]++;

            if (mp.count(c) && mp[c] == mp1[c]) {
                have++;
            }
            while (have == need) {
                if ((r-l+1) < resLen) {
                    resLen = r-l+1;
                    res = {l, r};
                }

                mp1[s[l]]--;
                if (mp.count(s[l]) && mp1[s[l]] < mp[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
