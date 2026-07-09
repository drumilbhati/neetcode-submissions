class TimeMap {
public:
    map<string, set<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto& st = mp[key];
        auto it = st.upper_bound({timestamp, "\xff"});
        if (it != st.begin()) {
            return prev(it)->second;
        }
        return "";
    }
};
