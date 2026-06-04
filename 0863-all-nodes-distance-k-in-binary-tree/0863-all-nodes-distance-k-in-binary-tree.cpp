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
    unordered_map<int,vector<int>>adj;
    void build(TreeNode* root){
        if(!root) return;
        if(root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        build(root->left);
        build(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        vector<int>ans;
        queue<int>q;
        unordered_set<int>vis;
        q.push(target->val);
        vis.insert(target->val);
        int level=-1;
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                for(auto &neigh:adj[it]){
                    if(!vis.count(neigh)){
                    q.push(neigh);
                    vis.insert(neigh);
                    }
                }
                if(level==k) ans.push_back(it);
            }
            if(level==k) break;
        }
        return ans;
    }
};