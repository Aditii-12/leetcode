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
    unordered_map<int,vector<int>>adj;
    void build(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right);
        }

    }
    int amountOfTime(TreeNode* root, int start) {
        build(root);
        queue<int>q;
        unordered_set<int>vis;
        q.push(start);
        vis.insert(start);
        int time=-1;
        while(!q.empty()){
            int n=q.size();
            time++;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                for(auto &neigh:adj[it]){
                    if(!vis.count(neigh)) {
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
        }
        return time;

    }
};