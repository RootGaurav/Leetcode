class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ansi;
        unordered_map<string,int> mp;
        for(int i=0;i<s1.length();i++)
        {
            string ans="";
            int j=i;
            while(j<s1.length() && s1[j]!=' ')
            { 
                j++;
            }
            ans=s1.substr(i,j-i);
            i=j;
            mp[ans]++;
        }
        for(int i=0;i<s2.length();i++)
        {
             string ans="";
             int j=i;
            while(j<s2.length() && s2[j]!=' ')
            {
                j++;
            }
            ans=s2.substr(i,j-i);
            i=j;
            mp[ans]++;
        }
        for(auto i:mp)
        {
            if(i.second == 1) ansi.push_back(i.first);

        }
        return ansi;
    }
};