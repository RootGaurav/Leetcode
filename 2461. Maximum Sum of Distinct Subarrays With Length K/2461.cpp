class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0;
        int low = 0;
        int high = 0;
        unordered_map<int,int>mp;
        int count = 0;
        long long res = 0;
        while(high < nums.size()) {
            mp[nums[high]]++;
            count++;
            currSum += nums[high];
            if(count == k) {
                if(mp.size() != k) {
                    currSum -= nums[low];
                    mp[nums[low]]--;
                    if(mp[nums[low]] == 0)
                        mp.erase(nums[low]);
                    low++;
                    count--;
                } else {
                    res = max(res, currSum);
                }
            } else {
                while(count > k) {
                    currSum -= nums[low];
                    mp[nums[low]]--;
                    if(mp[nums[low]] == 0)
                        mp.erase(nums[low]);
                    low++;
                    count--;
                }
                if(count == k) {
                if(mp.size() != k) {
                    currSum -= nums[low];
                    mp[nums[low]]--;
                    if(mp[nums[low]] == 0)
                        mp.erase(nums[low]);
                    low++;
                    count--;
                } else {
                    res = max(res, currSum);
                }
            } 
            }
            high++;
        }
        return res;
    }
};