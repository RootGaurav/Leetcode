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

    int solve(TreeNode* root,int sum,string path )
    {   if(root==NULL) return 0;
        if(root->left==NULL && root ->right ==NULL) return stoi(path+to_string(root->val));

        path+=to_string(root->val);
        int ls=solve(root->left,sum,path);
        int rs=solve(root->right,sum,path);
        return ls+rs;


    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root ->right ==NULL) return root->val;
        string path=" ";
        int sum=0; 
        return solve(root,sum,path);
        
    }
};


//second solution


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     vector<int> ans;
//     int sum=0;
//     int totalsum=0;

// public:
//     void solve(TreeNode *root)
//     {
//         if(root==NULL) return ;

//         ans.push_back(root->val);
//         if(root->left==NULL && root->right==NULL)
//         {
//             for(int i:ans) sum=(sum*10)+i;
//             totalsum+=sum;
//             sum=0;
//         }
//         solve(root->left);
//         solve(root->right);
//         ans.pop_back();
//     }
//     int sumNumbers(TreeNode* root) {
//         if(root==NULL) return 0;
//         solve(root);
//         return totalsum;
        
//     }
// };