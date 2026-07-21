class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char, int> mp;
        for (char c: tasks) {
            mp[c]++;
        }
        for (auto& [x, y]: mp) {
            pq.push(y);
        }

        queue<pair<int, int>> q;
        int t = 1;
        while (!pq.empty() || !q.empty()) {
            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                if (cnt > 1) {
                    q.push({cnt-1, t+n});
                }
            }
            if (!q.empty() && q.front().second == t) {
                pq.push(q.front().first);
                q.pop();
            }
            t++;
        }
        return t-1;
    }
};
