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
    vector<TreeNode*>ans;
    unordered_set<int>st;
    TreeNode* dfs(TreeNode* root,vector<int>& to_del){
        if(!root) return NULL;
        root->left=dfs(root->left,to_del);
        root->right=dfs(root->right,to_del);
        if(st.count(root->val)){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        for(auto x:to_del){
            st.insert(x);
        }
        root=dfs(root,to_del);
        if(root) ans.push_back(root);
        return ans;
    }
};