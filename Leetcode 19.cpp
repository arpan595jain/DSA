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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int len=0;

        //Calculate length of linked list
        while(curr!=NULL){ 
            curr=curr->next;
            len++;
        }

        curr=head;   //reinitialise head
        int pos=len-n-1;    //we will delete the node at pos+1, so travel upto position = pos

        if(pos<0){  //if pos<0 ti means head is to be deleted so delete head
            head=head->next;
            delete curr;
            return head;
        }

        while(pos--)curr=curr->next;  //traverse to position = pos

        //delete next element from element at pos, and rejoin linked list
        ListNode* forward=curr->next;
        curr->next=curr->next->next;
        delete forward;

        return head;
    }
};
