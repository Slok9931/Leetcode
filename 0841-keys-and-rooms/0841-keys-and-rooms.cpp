class Solution {
public:
    void dfs(int node, vector<vector<int>> &rooms, vector<bool> &vis){
        if(vis[node]) return;
        vis[node] = true;
        for(int i:rooms[node]) dfs(i, rooms, vis);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(0, rooms, vis);
        for(int i=0;i<rooms.size();i++) if(!vis[i]) return false;
        return true;
    }
};
