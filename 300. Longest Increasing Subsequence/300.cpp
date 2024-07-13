class Solution {
public:

    int solve(vector<int>& nums,int prev,int index,vector<vector<int>>& dp)
    {
        if(index>=nums.size())
        {return 0;

        }

        if(prev!=-1 && dp[prev][index]!=-1)
        {
            return dp[prev][index];
        }
        int take=0,nottake;

        if(prev==-1 || nums[index]>nums[prev])
        {
            take=solve(nums,index,index+1,dp)+1;
        }
       
        nottake=solve(nums,prev,index+1,dp);
        
        if(prev!=-1)
        {

        dp[prev][index]=max(take,nottake);
        }
        return max(take,nottake);

        
        

    }

    int lengthOfLIS(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(nums,-1,0,dp);

        
    }
};