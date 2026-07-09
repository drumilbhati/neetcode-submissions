class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        st.push({-1, INT_MAX});
    }
    
    void push(int val) {
        int mn = min(val, st.top().second);
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
