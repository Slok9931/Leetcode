class Solution {
public:
    bool solve(vector<int>& weights, int days, int mid){
        int count = 1, sum = 0;
        for (int w : weights) {
            if (sum + w > mid) {
                count++;
                sum = 0;
            }
            sum += w;
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i:weights) sum += i;
        int s = *max_element(weights.begin(), weights.end()), e = sum, ans = sum;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(solve(weights, days, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};
