/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int currentVal, int & ans) {
        if (root == NULL) return;
        currentVal = (currentVal << 1) | root->val;
        if (root->left == NULL && root->right == NULL) {
            ans += currentVal;
        }
        solve(root->left, currentVal, ans);
        solve(root->right, currentVal, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans; 
    }
};
