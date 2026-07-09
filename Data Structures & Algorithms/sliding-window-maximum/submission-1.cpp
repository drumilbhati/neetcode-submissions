class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        multiset<int> ms;

        for (int i=0; i<n; i++) {
            ms.insert(nums[i]);

            if (i >= k) {
                ms.erase(ms.find(nums[i-k]));
            }

            if (i >= k-1) {
                ans.push_back(*ms.rbegin());
            }
        }
        return ans;
    }
};
