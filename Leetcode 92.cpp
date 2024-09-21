struct  ListNode *top=NULL;
 int isfull(struct ListNode *t)
{
    struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
    if(q==NULL)
    {
        return 1;
    }
    else
    return 0;
}
int isempty(struct ListNode *t)
{
    if(t==NULL)
    {
        return 1;
    }
    else
    return 0;
}
struct ListNode *push(struct ListNode *t,int val)
{
    if(isfull(t))
    printf("stack full");
    else
    {
        struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
        q->val=val;
        q->next=t;
        t=q;
        return t;
    }
    return t;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *p=head;
    struct ListNode *q=head;
         struct ListNode *top=NULL;
    int i;
    for(i=0;i<left-1;i++)
    {
        p=p->next;
    }
    for(i=0;i<right-1;i++)
    {
        q=q->next;
    }
    while(p!=q)
    {
        top=push(top,p->val);
        p=p->next;
    }
    top=push(top,p->val);
struct ListNode* o = top;
    while (o->next != NULL) {
        o = o->next;
    }
    o->next = q->next;
    struct ListNode* e = head;
    if (left > 1) {
        for (i = 0; i < left - 2; i++) {
            e = e->next;
        }
        e->next = top;
        return head;
    } else {
        return top;
    }
}
