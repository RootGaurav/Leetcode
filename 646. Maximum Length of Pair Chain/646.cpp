class Solution {
public:

int solve(vector<vector<int>>& nums,int prev,int index,vector<vector<int>>& dp)
    {
        if(index>=nums.size())
        {return 0;

        }

        if(prev!=-1 && dp[prev][index]!=-1)
        {
            return dp[prev][index];
        }
        int take=0,nottake;

        if(prev==-1 || nums[index][0]>nums[prev][1])
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
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans=0;
        int n=pairs.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,-1,0,dp);

    }
};