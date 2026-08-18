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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            long long s, e;
            for(int i=0;i<n;i++){
                auto t = q.front();
                q.pop();
                if(i == 0) s = t.second;
                if(i == n-1) e = t.second;
                if(t.first -> left) q.push({t.first -> left, 2 * t.second + 1 - s});
                if(t.first -> right) q.push({t.first -> right, 2 * t.second + 2 - s});
            }
            ans = max(ans , e - s + 1);
        }
        return ans;
    }
};
