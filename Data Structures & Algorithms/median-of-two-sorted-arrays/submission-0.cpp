class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int INF = 1e9;

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int half = total / 2;

        int lo = -1, hi = nums1.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int i = mid;
            int j = half - i - 2;

            int aleft = (i >= 0 ? nums1[i] : -INF);
            int aright = (i < n-1 ? nums1[i+1] : INF);
            int bleft = (j >= 0 ? nums2[j] : -INF);
            int bright = (j < m-1 ? nums2[j+1] : INF);

            if (aleft <= bright && bleft <= aright) {
                if (total & 1) {
                    return min(aright, bright);
                } else {
                    return (max(aleft, bleft) + min(aright, bright)) / 2.0;
                }
            } else if (aleft > bright) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return -1;
    }
};
