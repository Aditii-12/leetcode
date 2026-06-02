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
    string ans="";
    void dfs(TreeNode* root,string &path){
        if(!root) return;
        path.push_back('a'+root->val);
        if(!root->left && !root->right){
            string curr=path;
            reverse(curr.begin(),curr.end());
            if(ans==""||curr<ans) ans=curr;
        }
        dfs(root->left,path);
        dfs(root->right,path);
        path.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string path="";
        dfs(root,path);
        return ans;
    }
};