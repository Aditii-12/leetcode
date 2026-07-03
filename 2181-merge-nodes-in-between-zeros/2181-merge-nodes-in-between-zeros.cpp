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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        ListNode* left=head;
        ListNode* right=head->next;
        while (right) {
            int sum=0;
            while(right->val!=0) {
                sum+=right->val;
                right=right->next;
            }
            tail->next=new ListNode(sum);
            tail=tail->next;

            left=right;
            right=right->next;
        }
        return dummy->next;
    }
};