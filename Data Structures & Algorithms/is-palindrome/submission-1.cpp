class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;

        while (l <= r) {
            while (l <= r && !isalnum(s[l])) l++;
            while (l <= r && !isalnum(s[r])) r--;

            if (l > r) break;

            char c = tolower(s[l]);
            char d = tolower(s[r]);

            if (c != d) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
