class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> timeDist(n, vector<int>(m, INT_MAX));
        timeDist[0][0] = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int time = i.first;
            int row = i.second.first;
            int col = i.second.second;
            if(row == n-1 && col == m-1) return time;
            if(time > timeDist[row][col]) continue;
            for(int k=0;k<4;k++){
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newTime = max(moveTime[newRow][newCol], time)+1;
                    if(newTime < timeDist[newRow][newCol]){
                        timeDist[newRow][newCol] = newTime;
                        pq.push({newTime, {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};
