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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
         int l=maxDepth(root->left);
         int r=maxDepth(root->right);
         return 1+max(l,r);
         }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int hl=maxDepth(root->left);
        int hr=maxDepth(root->right);
        if(abs(hl-hr)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};