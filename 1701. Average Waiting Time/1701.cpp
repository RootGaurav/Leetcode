class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double currtime=customers[0][0],waiting=0;
        for(int i=0;i<customers.size();i++)
        {

            if(customers[i][0] > currtime)
            {
                currtime=customers[i][0];
            }
            waiting+=currtime-customers[i][0];
            waiting+=customers[i][1];
            currtime+=customers[i][1];
        }
        return waiting/customers.size();
    }
};