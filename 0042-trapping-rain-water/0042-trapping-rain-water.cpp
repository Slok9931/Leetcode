class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = -1, rightMax = -1;
        int ans = 0;
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax) ans += leftMax - height[left++];
            else ans += rightMax - height[right--];
        }
        return ans;
    }
};
