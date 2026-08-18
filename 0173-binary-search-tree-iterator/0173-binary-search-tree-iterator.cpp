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
class BSTIterator {
public:
    void pushLeft(TreeNode* root, stack<TreeNode*>& in) {
       while(root){
        ino.push(root);
        root=root->left;
       }
    }
    stack<TreeNode*> ino;
    BSTIterator(TreeNode* root) { pushLeft(root, ino); }
    // print the next element if it exist
    int next() {
       TreeNode*node=ino.top();
       ino.pop();
       if(node->right){
       pushLeft(node->right,ino);
       }
       return node->val;
    }
    // for checking whether it has the next element or not;
    bool hasNext() {
        if (ino.empty())
            return false;
        else
            return true;
    }
};
