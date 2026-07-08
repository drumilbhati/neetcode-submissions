class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp1(26), mp2(26);
        for (char c: s) {
            mp1[c-'a']++;
        }
        for (char c: t) {
            mp2[c-'a']++;
        }
        for (int i=0; i<26; i++) {
            if (mp1[i] != mp2[i]) {
                return false;
            }
        }
        return true;
    }
};
