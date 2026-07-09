class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) {
            a[i] = {position[i], speed[i]};
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x.first < y.first;
        });

        int ans = n;
        double t = 0;
        for (int i=n-1; i>=0; i--) {
            double mt = (1.0 * target - a[i].first) / a[i].second;
            if (t >= mt) {
                ans--;
            }
            t = max(t, mt);
        }
        return ans;
    }
};
