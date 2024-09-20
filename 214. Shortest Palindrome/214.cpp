class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;
        int n = new_s.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i)
        {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j])
                j = lps[j - 1];            
            if (new_s[i] == new_s[j])
                ++j;            
            lps[i] = j;
        }
        int palindrome_len = lps[n - 1];
        string add_on = s.substr(palindrome_len);
        reverse(add_on.begin(), add_on.end());
        return add_on + s;
    }
};