class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp=score;
        int n=score.size();
        vector<string> ans(n);
        unordered_map<int,string> mp;
        sort(score.begin(),score.end(),greater<int> ());
        for(int i=0;i<n;i++)
        {
            if(i<=2)
            {
                if(i==0) mp[score[i]]="Gold Medal";
                if(i==1) mp[score[i]]="Silver Medal";
                if(i==2) mp[score[i]]="Bronze Medal";
                
            }
            else
            mp[score[i]]=to_string(i+1);
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=mp[temp[i]];
        }
        return ans;
    }
};