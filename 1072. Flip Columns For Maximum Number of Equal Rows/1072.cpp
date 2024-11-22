class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(m==1)return n;
        map<vector<int>,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[matrix[i]]++;
        }
        for(int i=0;i<n;i++){
            vector<int> v;
            vector<int> v1 = matrix[i];
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    v.push_back(0);
                }else{
                    v.push_back(1);
                }
            }
            
            if(mp.count(v))ans=max(ans,mp[v]+mp[v1]);
        }
     
        for(auto it:mp)ans=max(ans,it.second);
        return ans;
    }
};