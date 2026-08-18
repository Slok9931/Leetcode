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
    void solve(TreeNode* root, vector<int> &str){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            str.push_back(root -> val);
        }
        solve(root -> left, str);
        solve(root -> right, str);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> str1 , str2; 
        solve(root1, str1);
        solve(root2, str2);
        if(str1 == str2) return true;
        else return false;
    }
};
