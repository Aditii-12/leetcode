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
    int path(TreeNode* root,long long target){
        if(!root) return 0;
        int ans=0;
        if(root->val==target) ans++;
        ans+=path(root->left,target-root->val);
        ans+=path(root->right,target-root->val);
        return ans;
    }
    int start(TreeNode* root,long long target){
        if(!root) return 0;
        return path(root,target)+start(root->left,target)+start(root->right,target);
    }
    int pathSum(TreeNode* root, int targetsum) {
        return start(root,targetsum);
    }
};