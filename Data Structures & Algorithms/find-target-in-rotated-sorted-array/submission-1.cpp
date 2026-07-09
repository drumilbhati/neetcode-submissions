class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int mn = 0;
        int lo = 0, hi = n-1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        mn = lo;
    
        lo = 0, hi = mn-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        lo = mn, hi = n-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return -1;
    }
};
