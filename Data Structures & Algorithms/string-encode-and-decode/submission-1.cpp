class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string& st: strs) {
            s += to_string(st.size());
            s += "_";
            s += st;
        }
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> strs;
        for (int i=0; i<n;) {
            int len = 0;
            while (s[i] != '_') {
                len = (len * 10) + (s[i]-'0');
                i++;
            }
            strs.push_back(s.substr(i+1, len));
            i += len+1;
        }
        return strs;
    }
};
