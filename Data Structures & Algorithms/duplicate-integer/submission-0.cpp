class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (int x: nums) {
            if (mp.count(x)) return true;
            mp[x]++;
        }
        return false;
    }
};