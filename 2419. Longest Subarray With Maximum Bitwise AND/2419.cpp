class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int size = 0,res = 0,cur_max = 0;
             for(int i: nums)
             {
                if(i > cur_max)
                {
                    cur_max = i;
                    size = 1;
                    res = 0;
                }
                else if(i == cur_max)
                {
                    size = size +1;
                }
                else
                {
                    size = 0;
                }
                res = max(res,size);
             }
             return res; 
    }
};