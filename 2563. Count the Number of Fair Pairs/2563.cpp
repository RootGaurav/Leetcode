class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0;
        sort(nums.begin(),nums.end());
        deque<int> ans;
        for(auto i:nums)
        {
            ans.push_back(i);
        }
        for(int i=0;i<nums.size();i++)
        {
        ans.pop_front();
        auto low=lower_bound(ans.begin(),ans.end(),(lower-nums[i]));
        auto high=upper_bound(ans.begin(),ans.end(),upper-nums[i]);
        count+=(high-low); 
        }
        return count;
    }
};