class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newnode=new ListNode(-1);
        ListNode* temp=newnode;
        ListNode* head1=list1;
        ListNode* head2=list2;
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1!=NULL)
        {
            temp->next=head1;
        }
        if(head2!=NULL)
        {
            temp->next=head2;
        }
        return newnode->next;
    }
};
