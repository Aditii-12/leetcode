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
    TreeNode* func(TreeNode* root,int p,int q){
        if(!root) return NULL;
        if(root->val==p || root->val==q) return root;
        TreeNode* left=func(root->left,p,q);
        TreeNode* right=func(root->right,p,q);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p->val,q->val);
    }
};