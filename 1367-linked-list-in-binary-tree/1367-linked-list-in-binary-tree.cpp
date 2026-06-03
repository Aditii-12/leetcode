/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool match(TreeNode* root,ListNode* head){
        if(!head) return 1;
        if(!root) return 0;
        if(root->val!=head->val) return 0;
        return match(root->left,head->next)||match(root->right,head->next);
    }
    bool dfs(TreeNode* root,ListNode* head){
        if(!root) return 0;
        return match(root,head)||dfs(root->left,head)||dfs(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root,head);
    }
};