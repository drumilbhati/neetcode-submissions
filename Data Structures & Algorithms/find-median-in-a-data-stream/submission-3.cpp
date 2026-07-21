class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<>> minHeap;
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        n++;
    }
    
    double findMedian() {
        if (n & 1) {
            if (minHeap.size() > maxHeap.size()) {
                return minHeap.top();
            } else {
                return maxHeap.top();
            }
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};
