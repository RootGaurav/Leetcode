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
    int solve(int a,int b)
    {
        if(a==0) return b;
        if(b==0) return a;

        if(a==b) return a;
        if(a>b) return solve(a-b,b);
        else  return solve(a,b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
       while(head && head->next)
       {
        ListNode* gcd=new ListNode();
         gcd->val=solve(head->val,head->next->val);
        gcd->next=head->next;
        head->next=gcd;
        head=head->next->next;
       }
       return temp;
    }
};