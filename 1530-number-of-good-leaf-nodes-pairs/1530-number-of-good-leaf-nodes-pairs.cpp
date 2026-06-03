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
    int ans=0;
    vector<int>dfs(TreeNode* root,int dist){
        if(!root) return {};
        if(!root->left && !root->right)
            return {1};
        vector<int> left=dfs(root->left,dist);
        vector<int> right=dfs(root->right,dist);
        for(auto l:left){
            for(auto r:right){
                if(l+r<=dist) ans++;
            }
        }
        vector<int>curr;
        for(auto x:left) curr.push_back(x+1);
        for(auto x:right) curr.push_back(x+1);
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }
};