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
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        int le=0;
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            le++;
            int temp=0;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* no=q.front();
                q.pop();
                temp+=no->val;

                if(no->left!=nullptr) q.push(no->left);
                if(no->right!=nullptr) q.push(no->right);
            }
            if(temp>maxi){
                maxi=temp;
                ans=le;
            }
        }
        return ans;
    }
};