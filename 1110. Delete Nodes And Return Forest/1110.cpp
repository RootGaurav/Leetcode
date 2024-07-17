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
    bool solve(TreeNode* root,vector<int> to_delete,vector<TreeNode*> &ans)
    {
        if(root==nullptr) return false;

        

        bool left= solve(root->left,to_delete,ans);
        if(left) root->left=nullptr;
        bool right=solve(root->right,to_delete,ans);
        if(right) root->right=nullptr;
        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end())
        {
            if(root->left )ans.push_back(root->left);
            if(root->right )ans.push_back(root->right);
            return true;
        }

        return false;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        bool hehe=solve(root,to_delete,ans);
           if(find(to_delete.begin(),to_delete.end(),root->val)==to_delete.end())ans.push_back(root);
        return ans;
    }
};