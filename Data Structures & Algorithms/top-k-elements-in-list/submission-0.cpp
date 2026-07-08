class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int x: nums) {
            mp[x]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto& x, auto& y) {
            if (x.second == y.second) {
                return x.first < y.first;
            }
            return x.second > y.second;
        });

        vector<int> ans(k);
        for (int i=0; i<k; i++) {
            ans[i] = v[i].first;
        }
        return ans;
    }
};
