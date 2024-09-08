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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int partSize = size / k; 
        int extra = size % k;
        vector<ListNode*> ans(k,NULL);
        temp=head;
        for(int i=0;i<k && temp;i++){
            ans[i]=temp;
            int currPartSize=partSize;
            if(extra>0){
                currPartSize+=1;
            }
            for(int j=1;j<currPartSize;j++){
                if(temp){
                    temp=temp->next;
                }
            }
            if(temp){
                ListNode* nextPart=temp->next;
                temp->next=NULL;
                temp=nextPart;
            }
            if(extra>0){
                extra--;
            }

        }
        return ans;
    }
};