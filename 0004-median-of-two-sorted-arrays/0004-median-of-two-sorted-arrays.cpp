class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int s = 0, e = n1, n = n1 + n2;
        while(s <= e){
            int mid1 = s + (e-s)/2, mid2 = (n+1)/2 - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            else if(l1 > r2) e = mid1 - 1;
            else s = mid1 + 1;
        }
        return 0.0;
    }
};
