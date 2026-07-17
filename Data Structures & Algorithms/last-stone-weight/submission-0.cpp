class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int s: stones) {
            pq.push(s);
        }
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (pq.empty()) return x;
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(max(x - y, y - x));
            }
        }
        return 0;
    }
};
