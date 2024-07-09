class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* p=head;
        int mx=0;
        stack<int>st;
        while(p){
            st.push(p->val);
            p=p->next;
        }
        while(st.size()){
            mx=max(mx,st.top()+head->val);
            head=head->next;
            st.pop();
        }
        return mx;
    }
};
