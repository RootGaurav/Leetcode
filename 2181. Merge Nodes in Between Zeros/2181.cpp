class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* ret = res;
        int sm = 0;
        head = head->next;
        
        while(head != NULL){
            if(head->val == 0){
                res->next = new ListNode(sm);
                res = res->next;
                sm = 0;
            } else {
                sm += head->val;
            }
            head = head->next;
        }
        
        return ret->next;
    }
};