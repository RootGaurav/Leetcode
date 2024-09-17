class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        
        for(int k=0;k<=31;k++)
        {
            int temp=(1<<k);
            int c0=0,c1=0;
            for(auto &num:nums)
            {
                if((num & temp)==0) c0++;
                else c1++;
            }
            if(c1%3==1) ans=ans|temp;
        }
        return ans;
    }
};