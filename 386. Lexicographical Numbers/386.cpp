

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                if (curr >= n) {
                    curr /= 10;
                }
                curr++;
                while (curr % 10 == 0) {
                    curr /= 10;
                }
            }
        }
        return result;
    }
};
