class Solution {
public:
    int minSwaps(string s) {
        int open = 0, mismatch = 0;
        for (char ch : s) {
            if (ch == '[') {
                open++;
            } else if (open > 0) {
                open--;
            } else {
                mismatch++;
            }
        }
        return (mismatch +1) / 2;
    }
};