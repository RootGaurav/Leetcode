class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(int num:rolls)
        {
            sum+=num;
        }
        int value=mean*(n+rolls.size())-sum;
        if (value < n || value > 6 * n) {
            return {};  
        }
        float ansmod=value%n;
        int ansquo=value/n;
        vector<int>ans(n,ansquo);
        for(int i=0;i<ansmod;i++)
        {
            ans[i]++;
        }
        return ans;

    }
};