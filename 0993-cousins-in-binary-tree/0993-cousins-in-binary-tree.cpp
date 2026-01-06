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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr) return false;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,nullptr});

        while(!q.empty()){
            int sz=q.size();
            TreeNode* px=nullptr;
            TreeNode* py=nullptr;

            for(int i=0;i<sz;i++){
                auto[node,par] =q.front();
                q.pop();

                if(node->val==x) px=par;
                if(node->val==y) py=par;
                if (node->left) q.push({node->left,node});
                if (node->right) q.push({node->right,node});

            }
            //ab ek level finish hogyi h so we will check
            if(px&&py) //means both are not null ptr
                return px!=py;
            if(px||py) //koi ek b exist krta h to
                return 0;
        }
        return 0;
    }
};