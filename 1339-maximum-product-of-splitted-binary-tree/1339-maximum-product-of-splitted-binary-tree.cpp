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
using ll=long long;
class Solution {
public:
    ll ans=0;
    ll ts=0;
    const int mod= 1e9+7;
    ll dfssum(TreeNode* root){
        if(!root) return 0;
        return root->val+ dfssum(root->left)+dfssum(root->right);
    }
    ll dfs(TreeNode* root){
        if(!root) return 0;
        ll left=dfs(root->left);
        ll right=dfs(root->right);

        ll subtreesum=root->val+left+right;
        ll pro=subtreesum*(ts-subtreesum);
        ans=max(ans,pro);
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        ts=dfssum(root);
        dfs(root);
        return ans%mod;
    }
};