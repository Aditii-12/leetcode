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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long first=q.front().second; //us level ke first element ka idx
            long long last=q.back().second; //us level ke last element ka idx
            long long mini=q.front().second;
            ans=max(ans,last-first+1);
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                auto node=it.first;
                auto idx=it.second;
                idx-=mini;
                if(node->left) q.push({node->left,2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
            }
        }
        return ans;
    }
};