class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;

        int n=arr1.size();
        int m=arr2.size();

        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int num=arr1[i];
            while(num){
                mpp[num]++; 
                num=num/10; //O(log10(k)) k->max val of num
            }
           
        }  // O(nlog10(k))
       
       int mx=-1e9;
        for(int i=0;i<m;i++){
            int num=arr2[i];
            while(num){
                if(mpp.find(num)!=mpp.end()){
                    //found the prefix
                    int len=floor(log10(num) + 1); //O(1)
                    mx=max(mx,len);
                    break;
                }
                num=num/10;
            }
        }
         //O(mlog10(K));
        return mx==-1e9 ? 0 : mx;
    }
};