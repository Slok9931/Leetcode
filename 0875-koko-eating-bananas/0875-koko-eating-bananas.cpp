class Solution {
public:
    int solve(vector<int>& piles, int mid, int h){
        int count = 0;
        for(int i=0;i<piles.size();i++){
            count += (piles[i] + mid - 1) / mid;
            if(count > h) return count;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(), piles.end()), ans;
        while(s <= e){
            int mid = s + (e-s)/2, x = solve(piles, mid, h);
            if(x <= h){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};
