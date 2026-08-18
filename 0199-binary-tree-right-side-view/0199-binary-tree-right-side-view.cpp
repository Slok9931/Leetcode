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
    void solve(TreeNode* root, int level, vector<int>& ans){
        if(root != NULL && ans.size() < level) ans.push_back(root -> val);
        if(root != NULL){
            solve(root -> right, level+1, ans);
            solve(root -> left, level+1, ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 1, ans);
        return ans;
    }
};
