class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = n-1;
            while (l < r) {
                int sm = nums[i] + nums[l] + nums[r];
                if (sm > 0) {
                    r--;
                } else if (sm < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
