class Solution {
public:
    int getLucky(string s, int k) {
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            int m=s[i]-96;
            if(m>9)
            {
                while(m>0)
                {
                    int l=m%10;
                    count=count+l;
                    m=m/10;
                }
            }
            else
            {
                count=count+(s[i]-96);
            }
        }
        if(k==1)
        {
            return count;
        }
        else
        {
            
            for(int i=0;i<k-1;i++)
            {
                int j=0;
                while(count>0)
                {
                    j=j+count%10;
                    count=count/10;
                }
                count=j;
            }
        }
        return count;
    }
};