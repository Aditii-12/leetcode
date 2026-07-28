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
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto it:lists){
            if(it) pq.push(it);
        }
        ListNode* dumm=new ListNode(0);
        ListNode* tail=dumm;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            tail->next=curr;
            if(curr->next){
                pq.push(curr->next);
            }
            tail=tail->next;
        }
        return dumm->next;
    }
};