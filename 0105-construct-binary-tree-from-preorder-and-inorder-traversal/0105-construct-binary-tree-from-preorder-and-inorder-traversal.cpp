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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        int index = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + index);
        vector<int> leftIn(inorder.begin(), inorder.begin() + index);
        vector<int> rightPre(preorder.begin() + 1 + index, preorder.end());
        vector<int> rightIn(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
