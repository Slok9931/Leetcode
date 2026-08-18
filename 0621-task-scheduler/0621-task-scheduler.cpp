class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26, 0);
        for(char c:tasks) mp[c-'A']++;
        for(int i=0;i<26;i++){
            if(mp[i]) pq.push(mp[i]);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> v;
            int cycle = n+1;
            while(cycle && !pq.empty()){
                int top = pq.top();
                pq.pop();
                if(top > 1) v.push_back(top - 1);
                time++;
                cycle--;
            }
            for(int i:v) pq.push(i);
            if(pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};
