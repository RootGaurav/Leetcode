class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<int> temp=arr;
        unordered_map<int,int> ans;
        int c=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
            ans[arr[i]]=c;
            c++;
            }
            else ans[arr[i]]=c;
        }
        ans[arr[n-1]]=c;
        
        vector<int> anss(temp.size());
        for(int i=0;i<arr.size();i++)
        {
            temp[i]=ans[temp[i]];
        }
        return temp;
    }
};