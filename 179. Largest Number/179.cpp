class Solution {
public:
    
    struct comp
    {
        bool operator()(string a, string b) const
        {
        
            if(a+b > b+a)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
    
    
    string largestNumber(vector<int>& nums) 
    {
         
         vector<string> vs;
         for(auto num:nums)
         {
            vs.push_back(to_string(num));
         }
         sort(vs.begin(), vs.end(), comp());
         if(vs[0] == "0") return "0";
         string result;
         for(auto v: vs)
         {
            result+=v;
         }
         return result;
    }
};