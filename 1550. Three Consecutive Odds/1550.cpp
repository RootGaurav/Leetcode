class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flag=0;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2==0 )
            {
                flag=0;
                count=0;
            }
            else
            {
                if(flag!=0 || arr[i]%2!=0)
                {
                    count++;
                    flag=1;
                }
            }
            if(count==3) return true;
        }
        return false;
        
    }
};