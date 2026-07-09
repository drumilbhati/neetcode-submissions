class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> w(n, 1);

        auto solve = [&](vector<int>& h) -> void {
            stack<int> st;
            for (int i=0; i<n; i++) {
                while (!st.empty() && h[st.top()] > h[i]) {
                    w[st.top()] += i - st.top() - 1;
                    st.pop();
                }
                st.push(i);
            }
            while (!st.empty()) {
                w[st.top()] += n - st.top() - 1;
                st.pop();
            }
        };

        solve(heights);
        reverse(heights.begin(), heights.end());
        reverse(w.begin(), w.end());
        solve(heights);

        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans, w[i] * heights[i]);
        }
        return ans;
    }
};
