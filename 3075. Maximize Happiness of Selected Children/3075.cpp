class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long count=0;
        long long ans=0;
        sort(happiness.begin(),happiness.end(), greater <>());
        for(long long i:happiness)
        {
            if((i-count)<=0 || count==k) return ans;
            else
            {
               ans+=i-count;
               count++;
            }
        }
        return ans;
        
    }
};