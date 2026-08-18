class Twitter {
    map<int, deque<pair<int,int>>> mp;
    map<int, unordered_set<int>> st;
    int count = 0;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(mp[userId].size() == 10) mp[userId].pop_front();
        mp[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto t:mp[userId]){
            if(pq.size() < 10) pq.push(t);
            else if(pq.top().first < t.first){
                pq.pop();
                pq.push(t);
            }
        }
        for(int id:st[userId]){
            for(auto t:mp[id]){
                if(pq.size() < 10) pq.push(t);
                else if(pq.top().first < t.first){
                    pq.pop();
                    pq.push(t);
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        st[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        st[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
