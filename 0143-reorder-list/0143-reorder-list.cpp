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
    ListNode* reversefunc(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* sec=slow->next;
        slow->next=NULL;
        sec=reversefunc(sec);
        ListNode* fir=head;
        while(sec){
            ListNode* temp1=fir->next;
            ListNode* temp2=sec->next;
            fir->next=sec;
            sec->next=temp1;
            fir=temp1;
            sec=temp2;
        }
    }
};