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
    void traversal(TreeNode* root, unordered_map<int, int> &freq){
        if(root == NULL) return;
        freq[root -> val]++;
        traversal(root -> left, freq);
        traversal(root -> right, freq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        traversal(root, freq);
        vector <int> modes;
        int maxi = 0;
        for(auto i:freq) maxi = max(maxi, i.second);
        for(auto i:freq){
            if(i.second == maxi) modes.push_back(i.first);
        }
        return modes;
    }
};
