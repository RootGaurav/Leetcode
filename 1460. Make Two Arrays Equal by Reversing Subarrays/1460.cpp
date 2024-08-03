class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpa;
        unordered_map<int,int> mpt;
        for(int i:arr) mpa[i]++;
        for(int i:target) mpt[i]++;

        for(int i:arr)
        {
            if(find(target.begin(),target.end(),i)==target.end() || mpa[i]!=mpt[i] )
            {return false;
            }
        }
        return true;
    }
};