class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>arr;
         int n=difficulty.size();
     
         for(int i=0;i<n;i++)
         {
             arr.push_back({difficulty[i],profit[i]});
         }       
           sort(arr.begin(),arr.end());

             for(int i=1;i<n;i++) arr[i].second=max(arr[i].second,arr[i-1].second);
         long long maxprofit=0;
         int low,high,mid,temprofit;
         for(auto i:worker)
         {
             low=0,high=n-1,temprofit=0;
             while(low<=high)
             {
                 mid=(low+high)/2;
                 if(arr[mid].first<=i)        low=mid+1;
                 else high=mid-1;
             }
          if(high>=0)   maxprofit=(long long)maxprofit+arr[high].second;
         }
         return maxprofit;
    }
};