class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a || b || c)
        {
            if((c&1)==1)
            {
                if((a&1)==0 && (b&1)==0) flips++;
                
            }
            else
            {
                if((a&1)==1) flips++;
                if((b&1)==1) flips++; 
            }

            cout<<(a&1)<<" "<<(b&1)<<" "<<(c&1)<<endl;
            c>>=1;
            b>>=1;
            a>>=1;
        }
        return flips;
    }
};