class Solution {
private:
    // int search(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size() - 1;
    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] == target) {
    //             return mid;
    //         } 
    //         else if (nums[mid] < target) {
    //             left = mid + 1;  
    //         } 
    //         else {
    //             right = mid - 1;
    //         }
    //     }
    //     return left;
    // }
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return s;
    }
};
