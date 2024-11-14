class Solution {
    bool check(const vector<int>& quantities, int n, int max) {
        int curr = 0;
        for (int i = 0; i < quantities.size(); ++i) {
            curr += quantities[i] / max;
            curr += ((quantities[i] % max) != 0);
        }

        return curr <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(quantities, n, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};