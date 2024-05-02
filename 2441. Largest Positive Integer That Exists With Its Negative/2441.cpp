class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i:nums)
        {
            if(i<0) return -1;
            else
            {
                if(mp.find(-i)!=mp.end()) return i;
            }
        }
        return -1;
    }
};