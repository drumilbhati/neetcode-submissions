class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<string> str = strs;
        for (string& s: str) {
            sort(s.begin(), s.end());
        }

        vector<vector<string>> ans;
        vector<int> vis(n);
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                vector<string> v = {strs[i]};
                for (int j=i+1; j<n; j++) {
                    if (!vis[j] && str[i] == str[j]) {
                        v.push_back(strs[j]);
                        vis[j] = 1;
                    }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};
