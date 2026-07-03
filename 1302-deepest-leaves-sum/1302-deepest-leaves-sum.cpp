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
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            sum=0;
            int sz=q.size();
            while(sz--){
                TreeNode* fr=q.front();
                q.pop();
                sum+=fr->val;
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
        }
        return sum;
    }
};