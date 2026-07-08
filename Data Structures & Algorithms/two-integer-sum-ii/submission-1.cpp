class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            int t = target - nums[i];
            if (nums[i] > t) break;

            int j = lower_bound(nums.begin()+i+1, nums.end(), t) - nums.begin();
            if (j < n && nums[j] == t) {
                return {i+1, j+1};
            }
        }
        return {0, 0};
    }
};
