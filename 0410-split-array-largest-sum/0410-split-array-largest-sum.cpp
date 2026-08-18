class Solution {
public:
    bool solve(vector<int> &arr, int k, int mid){
        int ans = 1, sum = 0;
        for(int i=arr.size()-1;i>=0;i--){
            if(sum + arr[i] > mid){
                ans++;
                sum = arr[i];
            }
            else sum += arr[i];
        }
        return ans <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(), arr.end()), e = accumulate(arr.begin(), arr.end(), 0), ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(solve(arr, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};
