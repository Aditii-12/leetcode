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
    TreeNode* func(TreeNode* root){
        while(root->left) root=root->left;
        return root;
    }
    TreeNode* dfs(TreeNode* root,int key){
        if(!root) return NULL;
        if(key<root->val){
            root->left=dfs(root->left,key);
        }
        else if(key>root->val){
            root->right=dfs(root->right,key);
        }
        else{
            if(!root->left && !root->right) return NULL; //leaf node
            if(!root->left) return root->right; //only 1 child exists
            if(!root->right) return root->left;
            else{
                TreeNode* succ=func(root->right);
                root->val=succ->val;
                root->right=deleteNode(root->right,succ->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root,key);
    }
};