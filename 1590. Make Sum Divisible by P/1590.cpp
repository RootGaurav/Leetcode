#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum=0;
        for(int nums: nums){
            totalSum+=nums;
        }
        //storing remainder which we need to delete in totalSum itself,
        totalSum=totalSum%p;
        if(totalSum==0) return 0;

        unordered_map<int,int> prefixMod;
        prefixMod[0]=-1;//storing position of 0 at -1.
        long prefixSum=0;
        int minLength=nums.size();//initializing lentgth  of subarray as total array ,
        //if at last of code the minLength remains total length of given array then we will return -1,

        for(int i=0;i<nums.size();++i){
            prefixSum+=nums[i];
            int currentMod=prefixSum%p;
            int targetMod=(currentMod-totalSum+p)%p;

            if(prefixMod.find(targetMod)!=prefixMod.end()){
                minLength=min(minLength,i-prefixMod[targetMod]);
            }

            prefixMod[currentMod]=i;
        } 
        return minLength == nums.size()?-1:minLength;
    }
};