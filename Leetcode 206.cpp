struct ListNode* reverseList(struct ListNode* head){
struct ListNode* current = head;
      struct ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return prev;
};
