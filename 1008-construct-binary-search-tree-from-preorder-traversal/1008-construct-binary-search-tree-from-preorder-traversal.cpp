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
    int i=0;
    TreeNode* build(vector<int>& pre,int low,int high){
        if(i>=pre.size()) return NULL;
        int val=pre[i];
        if(val<low || val>high) return NULL;
        i++;
        TreeNode* root=new TreeNode(val);
        root->left=build(pre,low,val);
        root->right=build(pre,val,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MIN,INT_MAX);
    }
};