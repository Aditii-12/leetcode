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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>st;
        for(auto it:desc){
            auto par=it[0];
            auto ch=it[1];
            auto left=it[2];
            if(mpp.find(par)==mpp.end()){
                TreeNode* parent=new TreeNode(par);
                mpp[par]=parent;
            }
            if(mpp.find(ch)==mpp.end()){
                TreeNode* child=new TreeNode(ch);
                mpp[ch]=child;
            }
            if(left==1){
                mpp[par]->left=mpp[ch];
            }
            else{
                mpp[par]->right=mpp[ch];
            }
            st.insert(ch);
        }
        for(auto it:mpp){
            if(st.find(it.first)==st.end()) return it.second;
        }
        return NULL;
    }
};