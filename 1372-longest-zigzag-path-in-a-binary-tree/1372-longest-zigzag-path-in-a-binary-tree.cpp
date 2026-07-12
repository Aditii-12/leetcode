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
    void dfs(TreeNode* root, bool fl, int len){
        if(!root) return;
        ans=max(ans,len);
        if(fl==0){
            dfs(root->right,1,len+1);
            dfs(root->left,0,1);
        }
        else{
            dfs(root->left,0,len+1);
            dfs(root->right,1,1);
        }

    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,1);
        dfs(root->right,1,1);
        return ans;
    }
};