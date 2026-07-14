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
    void dfs(TreeNode* root,long long tar){
        if(!root) return;
        if(root->val==tar) ans++;
        dfs(root->left,tar-root->val);
        dfs(root->right,tar-root->val);
    }
    void func(TreeNode* root,long long tar){
        if(!root) return;
        dfs(root,tar);
        func(root->left,tar);
        func(root->right,tar);
    }
    int pathSum(TreeNode* root, int tar) {
        func(root,tar);
        return ans;
    }
};