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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        vector<long long>ls; //levelsum
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            ls.push_back(sum);
        }

        q.push(root);
        root->val=0;
        int lvl=0;

        while(!q.empty()){
            int sz=q.size();

            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                long long ss=0; //sibling sum;
                if(node->left) ss+=node->left->val;
                if(node->right) ss+=node->right->val;

                if(node->left){
                    node->left->val=ls[lvl+1]-ss;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=ls[lvl+1]-ss;
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return root;

    }
};