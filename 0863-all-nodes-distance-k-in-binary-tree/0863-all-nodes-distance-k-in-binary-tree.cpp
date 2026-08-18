/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createGraph(TreeNode* root, unordered_map<int, vector<int>> &adj){
        if(!root) return;
        if(root -> left){
            adj[root -> val].push_back(root -> left -> val);
            adj[root -> left -> val].push_back(root -> val);
            createGraph(root -> left, adj);
        }
        if(root -> right){
            adj[root -> val].push_back(root -> right -> val);
            adj[root -> right -> val].push_back(root -> val);
            createGraph(root -> right, adj);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        createGraph(root, adj);
        queue<int> q;
        q.push(target -> val);
        unordered_set<int> vis;
        vis.insert(target -> val);
        int level = 0;
        while(!q.empty()){
            vector<int> ans;
            int n = q.size();
            while(n--){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(int j=0;j<adj[node].size();j++){
                    int x = adj[node][j];
                    if(vis.find(x) == vis.end()){
                        vis.insert(x);
                        q.push(x);
                    }
                }
            }
            level++;
            if(level == k+1) return ans;
        }
        return {};
    }
};
