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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode* temp =head;
       if(head->next== NULL){
        head= NULL;
        return head;

       }
       while(fast!=NULL&&fast->next!=NULL){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
       }
       temp->next=slow->next;
       slow=NULL;
       return head;
    }
};
