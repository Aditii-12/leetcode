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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool ans=1;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long prev;
            if(level%2==0)
                prev=LLONG_MIN;  //this is the most important part of this question
                //how we intialize prev according to the level 
            else
                prev=LLONG_MAX;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                if(level%2==0){
                    if(it->val%2==0) return 0;
                    if(it->val<=prev) return 0;
                }
                else{
                    if(it->val%2==1) return 0;
                    if(it->val>=prev) return 0;
                }
                prev=it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            level++;
        }
        return 1;
    }
};