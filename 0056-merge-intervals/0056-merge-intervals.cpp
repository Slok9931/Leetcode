class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= prev[1]) prev[1] = max(prev[1], intervals[i][1]);
            else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
