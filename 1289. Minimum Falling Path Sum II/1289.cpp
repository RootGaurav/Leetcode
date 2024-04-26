class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            dp[0][i]=grid[0][i];
        }
        
        int mini=INT_MAX;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int ans=INT_MAX;
                for(int k=0;k<grid.size();k++){
                    if(j==k) continue;
                    ans=min(ans,grid[i][j]+dp[i-1][k]);
                }
                dp[i][j]=ans;
            }
        }
        for(int i=0;i<grid[0].size();i++){
            mini=min(mini,dp[grid.size()-1][i]);
        }
        return mini;
    }
};