class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool> vis(friends.size(), false);
        queue<pair<int, int>>q;
        q.push({id, 0});
        vis[id] = true;
        vector<int> frnd;
        while(!q.empty()){
            auto [node, lvl] = q.front();
            q.pop();
            if(lvl == level){
                frnd.push_back(node);
                continue;
            }
            for(int i:friends[node]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push({i, lvl + 1});
                }
            }
        }
        unordered_map<string, int> freq;
        for(int x:frnd){
            for(string s:watchedVideos[x]) freq[s]++;
        }
        vector<pair<int, string>> v;
        for(auto i:freq) v.push_back({i.second, i.first});
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto i:v) ans.push_back(i.second);
        return ans;
    }
};
