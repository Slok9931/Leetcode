class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int count = 1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] > end){
                count++;
                end = intervals[i][1];
            }
            else{
                end = min(end, intervals[i][1]);
            }
        }
        return count;
    }
};
