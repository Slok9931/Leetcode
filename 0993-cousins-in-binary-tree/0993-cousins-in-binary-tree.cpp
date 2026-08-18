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
    int xdep, ydep, xpar, ypar;
    void solve(TreeNode* root, int x, int y, int depth, int parent){
        if(root == NULL) return;
        if(root -> val == x){
            xdep = depth;
            xpar = parent;
            return;
        }
        if(root -> val == y){
            ydep = depth;
            ypar = parent;
            return;
        }
        solve(root -> left, x, y, depth+1, root -> val);
        solve(root -> right, x, y, depth+1, root -> val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> val == x || root -> val == y) return false;
        solve(root, x, y, 0, -1);
        if(xdep == ydep && xpar != ypar) return true;
        return false;
    }
};
