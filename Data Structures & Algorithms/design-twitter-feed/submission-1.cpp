class Twitter {
public:
    int time;
    map<int, deque<pair<int, int>>> tweets;
    map<int, set<int>> following;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        if (tweets[userId].size() > 10) tweets[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto& t: tweets[userId]) {
            pq.push(t);
        }
        for (auto& followeeId: following[userId]) {
            if (followeeId == userId) continue;
            for (auto& t: tweets[followeeId]) {
                pq.push(t);
            }
        }
        vector<int> ans;
        while (ans.size() < 10 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
