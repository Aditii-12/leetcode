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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>child;
        for(auto &d:descriptions){
            auto parent=d[0];
            auto ch=d[1];
            auto left=d[2];
            if(mpp.find(parent)==mpp.end()){
                mpp[parent]=new TreeNode(parent);
            }
            if(mpp.find(ch)==mpp.end()){
                mpp[ch]=new TreeNode(ch);
            }
            if(left)
                mpp[parent]->left=mpp[ch];
            else 
                mpp[parent]->right=mpp[ch];

            child.insert(ch);
        }

        for(auto it:mpp){
            if(child.find(it.first)==child.end())
                return it.second;
        }
        return NULL;
    }
};