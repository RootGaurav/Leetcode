/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
     
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {

        unordered_map<int,TreeNode*> mpnode;
        unordered_map<TreeNode*,bool> hasparent;


        for(int i=0;i<des.size();i++)
        {
            TreeNode* node=nullptr;
            if(mpnode.find(des[i][0])==mpnode.end())
            {

            node=new TreeNode(des[i][0]);
            mpnode[des[i][0]]=node;
            }
            else 
            {
                node=mpnode[des[i][0]];
            }
            TreeNode* head=node;
            
            
            if(mpnode.find(des[i][1])==mpnode.end())
            {
             node=new TreeNode(des[i][1]);
             mpnode[des[i][1]]=node;
            }
            else 
            {
                node=mpnode[des[i][1]];
            }
            if(des[i][2]==1)
            {
                TreeNode* leftp=node;
                head->left=leftp;
            }
            else
            {
                TreeNode* rightp=node;
                head->right=rightp;
            }
            hasparent[node]=true;
            cout<<"node ="<<head->val<<endl;
            if(head->left) cout<<"node-left  ="<<head->left->val<<endl;
            if(head->right) cout<<"node-right ="<<head->right->val<<endl;
            
        }
        TreeNode* head=nullptr;
        
        for(auto i:mpnode)
        {
            if(hasparent.find(i.second)==hasparent.end()){
                head=i.second;
                break;
        }
        }
        return head;
    }
};