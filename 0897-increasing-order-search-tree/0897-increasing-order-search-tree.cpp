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
    void inorder(TreeNode* root, vector <int> &in){
        if(root == NULL) return;
        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }
    TreeNode* solve(vector <int> &in, int index){
        if(index >= in.size()) return NULL;
        TreeNode* root = new TreeNode(in[index]);
        root -> right = solve(in, index+1);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector <int> in;
        inorder(root, in);
        return solve(in, 0);
    }
};
