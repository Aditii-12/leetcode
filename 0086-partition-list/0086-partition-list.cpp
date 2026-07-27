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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smalld=new ListNode(0);
        ListNode* bigd=new ListNode(0);
        ListNode* small=smalld;
        ListNode* big=bigd;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                small->next=curr;
                small=small->next;
            }
            else{
                big->next=curr;
                big=big->next;
            }
            curr=curr->next;
        }
        big->next=nullptr;
        small->next=bigd->next;
        return smalld->next;
    }
};