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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
       
        vector<vector<int>> result(m, vector<int>(n, -1));
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        int direction=0;
        //direction 0 is -> left to right
        //direction 1 is top to down
        //direction 2 is <- right to left
        //direction 3 is Down to Top 
        while(top<=down&&left<=right)
        {
           if(direction==0)
           {
            for (int i=left;head!=NULL&&i<=right;i++)
            {
               result[top][i]=head->val;
                head=head->next;
            }
            top++;
           }
           if(direction==1)
           {
            for (int i=top;head!=NULL&&i<=down;i++)
            {
                result[i][right]=head->val;
                head=head->next;
            }
            right--;
           } 
           if (direction==2)
           {
            for(int i=right;head!=NULL&&i>=left;i--)
            {
              result[down][i]=head->val;
                head=head->next;
            }
            down--;
           }
           if(direction==3)
           {
            for(int i=down;head!=NULL&&i>=top;i--)
            {
              result[i][left]=head->val;
                head=head->next;
            }
            left++;
           }
            direction = (direction+1)%4;
        }
        return result;

    }
};