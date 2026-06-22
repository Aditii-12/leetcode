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
        ListNode* smalldum=new ListNode(0);
        ListNode* bigdum=new ListNode(0);
        ListNode* small=smalldum;
        ListNode* big=bigdum;
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
        small->next=bigdum->next;
        return smalldum->next;
    }
};