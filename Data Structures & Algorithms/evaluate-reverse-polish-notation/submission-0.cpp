class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        auto isspecial = [](string s) -> bool {
            return s == "+" || s == "-" || s == "*" || s == "/";
        };

        for (string& s: tokens) {
            if (isspecial(s)) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = 0;
                if (s == "+") {
                    res = a + b;
                } else if (s == "-") {
                    res = a - b;
                } else if (s == "*") {
                    res = a * b;
                } else {
                    res = a / b;
                }
                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
