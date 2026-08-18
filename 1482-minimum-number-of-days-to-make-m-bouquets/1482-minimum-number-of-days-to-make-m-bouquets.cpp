class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int mid){
        int ans = 0;
        for(int i=0;i<bloomDay.size();i++){
            int count = 0;
            while(i < bloomDay.size() && count < k && bloomDay[i] <= mid){
                count++;
                i++;
            }
            if(count == k){
                ans++;
                i--;
            }
            if(ans >= m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int s = 1, e = *max_element(bloomDay.begin(), bloomDay.end());
        while(s < e){
            int mid = s + (e-s)/2;
            if(solve(bloomDay, m, k, mid)) e = mid;
            else s = mid + 1;
        }
        return s;
    }
};
