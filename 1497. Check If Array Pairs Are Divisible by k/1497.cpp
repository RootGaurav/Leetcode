class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // int n = arr.size();
        // for(int i=0;i<n;i++){
        //     arr[i]=arr[i]%k;
        // }
        //   sort(arr.begin(),arr.end());
        // unordered_map<int,int>mp;

        // for(int i = 0;i<n;i++){
        //     if(arr[i]<0){
        //         mp[abs(arr[i])]++;
        //     }
        //     if(arr[i]>0 && mp.find(arr[i])!=mp.end() && mp[arr[i]] >0){
        //       mp[arr[i]]--;
        //          arr[i]=0;
        //     }
        // }
        // for(auto it:mp){
        //     if(it.second!=0) return false;
        // }
        // // for(int i = 0;i<n;i++){
        // //     if(mp.find(abs(arr[i]))!=mp.end()){
        // //         arr[i]=0;
        // //     }
        // // }

        // sort(arr.begin(),arr.end());
        
        // int start = -1;
        // int cnt=0;
        // for(int i = 0;i<n;i++){
        //    if(arr[i]>0 && start==-1) start=i;
        //    if(arr[i]>0) cnt++;
        // }
        //  if(start==-1) return true;
        // int i = start;
        // int j = n-1;
        
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<i<<" ";

        // if(cnt%2==1) return false;
        // while(i<j){
        //     if((arr[i]+arr[j])%k==0 ) {
        //         i++,j--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;
         

         int n = arr.size();

         vector<int>mp(k,0);

         for(int i = 0;i<n;i++){
            int rem = (arr[i]%k +k)%k;
            mp[rem]++;
         }

         if(mp[0]%2!=0) return false;

         for(int rem =1;rem<=k/2 ; rem++){
            int counterRem = k-rem;
            if(mp[counterRem]!=mp[rem]){
                return false;
            }
         }
         return true;
    }
};

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         unordered_map<int, int> remainderCount;

//         // Count the remainders of each element modulo k
//         for (int i = 0; i < arr.size(); i++) {
//             int remainder = ((arr[i] % k) + k) % k; // Ensure remainder is positive
//             remainderCount[remainder]++;
//         }

//         // Check if elements can be paired
//         for (auto& [remainder, count] : remainderCount) {
//             if (remainder == 0) {
//                 // Elements with remainder 0 must be paired among themselves, so count must be even
//                 if (count % 2 != 0) {
//                     return false;
//                 }
//             } else {
//                 int complement = k - remainder;
//                 // The count of elements with remainder must match the count of elements with the complement
//                 if (remainderCount[remainder] != remainderCount[complement]) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };