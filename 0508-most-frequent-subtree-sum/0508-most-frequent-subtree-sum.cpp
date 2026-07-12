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
    unordered_map<int,int>freq;
    int maxi=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int sum=l+r+root->val;
        freq[sum]++;
        maxi=max(maxi,freq[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>ans;
        for(auto it:freq){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }
};