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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        vector<int>temp;
        while(!q.empty()){
            int n=q.size();
            if(lvl%2==1){
                reverse(temp.begin(),temp.end());
                int i=0;
                for(int j=0;j<n;j++){
                    TreeNode* node=q.front();
                    q.pop();
                    node->val=temp[i++];
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                temp.clear();
            }
            else{
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            }
            lvl++;
        }
        return root;        
    }
};