class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<char, int> mp;
        for (char c: t) {
            mp[c]++;
        }

        auto check = [&](deque<char>& curr) -> bool {
            map<int, int> mp1;
            for (char c: curr) {
                mp1[c]++;
            }
            for (auto& [x, y]: mp) {
                if (mp1[x] < y) return false;
            }
            return true;
        };

        int l=0, r=0;
        deque<char> curr, ans(n+1);
        for (; r < n; r++) {
            curr.push_back(s[r]);

            while (l <= r && check(curr)) {
                if (ans.size() > curr.size()) {
                    ans = curr;
                }
                curr.pop_front();
                l++;
            }
        }
        if (ans.size() == n+1) {
            return "";
        }
        string res = "";
        for (char c: ans) {
            res += c;
        }
        return res;
    }
};
