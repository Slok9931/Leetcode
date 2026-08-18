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
    void solve(TreeNode* root, set <int> &s){
        if(root == NULL) return;
        s.insert(root -> val);
        solve(root -> left, s);
        solve(root -> right, s);
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        set <int> s;
        solve(root, s);
        vector <int> ans;
        for(auto i:s) ans.push_back(i);
        return (ans.size() > 1) ? ans[1] : -1;
    }
};
