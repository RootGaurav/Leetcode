
#include<iostream.h>
#include<string>
using namespace<std>;

class Solution {
public:
    int longestIdealString(string s, int k) {
       int dp[26] = {};
    return k == 26 ? s.size() : accumulate(begin(s), end(s), 0, [&](int s, char ch){
        return max(s, dp[ch - 'a'] = 1 + *max_element(
            begin(dp) + max(0, ch - 'a' - k), begin(dp) + min(26, ch - 'a' + k + 1)));
    }); 
    }
};


int main()
{
    Solution obj=new Solution();
    obj.longestIdealString("hello",2);
    return 0;
}