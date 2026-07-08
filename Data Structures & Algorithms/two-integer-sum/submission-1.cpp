class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i=0; i<n; i++) {
            int t = target - nums[i];
            if (mp.count(t) && t != nums[i]) {
                return {i, mp[t][0]};
            } else if (mp.count(t) && mp[t].size() > 1) {
                return {i, mp[t][1]};
            }
        }
        return {0, 0};
    }
};
