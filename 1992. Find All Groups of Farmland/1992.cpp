class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, vector<int>&temp){
        if(i<0 || j<0 || i>=land.size() || j>=land[0].size() || !land[i][j])
            return;
        
		// Find the bottom-right corner
        if(i>temp[2]){
            temp[2] = i;
            temp[3] = j;
        }
        else if(i==temp[2] && j>temp[3])
            temp[3] = j;
        
        land[i][j]=0;
        dfs(land,i-1,j,temp);
        dfs(land,i+1,j,temp);
        dfs(land,i,j-1,temp);
        dfs(land,i,j+1,temp);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        for(int i=0;i<land.size();i++){
            for(int j = 0;j<land[0].size();j++){
                if(land[i][j]){
                    vector<int> temp = {i,j,i,j};
                    dfs(land,i,j,temp);
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};