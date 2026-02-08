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
    int maxd(TreeNode* root){
        if(!root) return 0;
        int l=maxd(root->left);
        int r=maxd(root->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int hl=maxd(root->left);
        int hr=maxd(root->right);
        if(abs(hl-hr)>1) return 0;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};