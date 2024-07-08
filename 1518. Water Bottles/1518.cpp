class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int required=numExchange;
        int count=full;
        int empty=full;
        int exchange;
        int left;
        while(empty>=required)
        {
            exchange=empty/required;
            left=empty%required;
            count+=exchange;
            empty+=exchange+left;
        }
        return count;
    }
};