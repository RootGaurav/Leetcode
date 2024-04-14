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
    void solve(TreeNode* root,int &sum,int flag)
    {
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL && flag) sum+=root->val;
        solve(root->left,sum,1);
        solve(root->right,sum,0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 0;
        int sum=0;
        solve(root,sum,0);
        return sum;
        
    }
};