class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        auto check = [&](int r) -> bool {
            int hours = 0;
            for (int i=0; i<n; i++) {
                hours += (piles[i] + r - 1) / r;
            }
            return hours <= h;
        };

        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};
