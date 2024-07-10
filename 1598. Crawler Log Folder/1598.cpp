class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;

        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="./")
            {
                continue;
            }
            else if(logs[i]=="../")
            {
                if(count!=0)count--;

            }
            else count++;
        }
        if(count<=0) return 0;
        else return count;
    }
};