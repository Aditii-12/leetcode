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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<int>p;
        int le=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            le++;
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* no=q.front();
                q.pop();
                sum+=no->val;
                if(no->left!=nullptr) q.push(no->left);
                if(no->right!=nullptr) q.push(no->right);
            }
            p.push_back(sum);
        }
        sort(p.rbegin(),p.rend());
        return p[k-1];
    }
};