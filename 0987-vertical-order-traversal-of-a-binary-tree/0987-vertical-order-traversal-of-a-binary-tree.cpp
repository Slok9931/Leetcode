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
    void dfs(TreeNode* node, int x, int y, map<int, multiset<pair <int, int>>>&mp){
        if(!node) return;
        mp[x].insert({y, node -> val});
        dfs(node -> left, x-1, y+1, mp);
        dfs(node -> right, x+1, y+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp;
        dfs(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(auto [x, st] : mp){
            ans.push_back({});
            for(auto [y, val] : st) ans.back().push_back(val);
        }
        return ans;
    }
};
