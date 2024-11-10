class Solution {
public:
    void lisf(vector<int> &lis,vector<int>& nums){
        vector<int> ans ;
        ans.push_back(nums[0]) ;
        lis[0] = 1 ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]) ;
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin() ;
                ans[index] = nums[i] ;
            }
            lis[i] = ans.size() ;
        }
    }


    int lds(vector<int> &lis, vector<int>& nums){
        vector<int> ans ;
        ans.push_back(nums.back()) ;
        int maxi = 1 ;
        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]) ;
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin() ;
                ans[index] = nums[i] ;
            }
            if(ans.size() > 1 && lis[i] > 1){
                lis[i] += ans.size() - 1 ;
                maxi = max(maxi,lis[i]) ;

            }

        }
        return maxi ;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis(nums.size()) ;
        lisf(lis,nums) ;
        int ans = lds(lis,nums) ;
        return nums.size() - ans ;

    }
};