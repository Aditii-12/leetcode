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
    bool func(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return 1;
        if(!root1 || !root2) return 0;
        if(root1->val != root2->val) return 0;
        return normal(root1,root2) || flipped(root1,root2);
    }
    bool flipped(TreeNode* root1, TreeNode* root2){
        return func(root1->left,root2->right) && func(root1->right,root2->left);
    }
    bool normal(TreeNode* root1, TreeNode* root2){
        return func(root1->left,root2->left) && func(root1->right,root2->right);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return func(root1,root2);
    }
};