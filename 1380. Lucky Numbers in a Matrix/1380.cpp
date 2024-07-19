class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> minarr;
        vector<int> maxarr;
        int mini,maxi;
        for(int i=0;i<n;i++)
        {
            mini=INT_MAX;
            
            for(int j=0;j<m;j++)
            {
                mini=min(mini,matrix[i][j]);
               
            }   
             minarr.push_back(mini);
        }   
        for(int i=0;i<m;i++)
        {
            maxi=INT_MIN;

            
            for(int j=0;j<n;j++)
            {
                maxi=max(maxi,matrix[j][i]);
                 
            }   
            
             maxarr.push_back(maxi);
        } 
        vector<int> ans;
        for(int i:maxarr)
        {
            if(find(minarr.begin(),minarr.end(),i)!=minarr.end())
            ans.push_back(i);
        }
        return ans;     
    }
};