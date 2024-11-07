class Solution {
public:
    int largestCombination(vector<int>& nums) {
     
        int max1Bit = 0;
        for(int b=0;b<32;b++){
            int curBit = 0;
            for(auto i:nums){
                if((i&(1<<b)) != 0) curBit++;
            }
            max1Bit = max(max1Bit,curBit);
        }
        return max1Bit;
    }
}; 