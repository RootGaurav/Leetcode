class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
      vector<int> res(n - k + 1, -1);

    for (int i = 0; i <= n - k; ++i) {
        bool is = true;
        for (int j = 1; j < k; ++j) {
            if (nums[i + j] != nums[i + j - 1] + 1) {
                is = false;
                break;
            }
        }
        if (is) {
            res[i] = *max_element(nums.begin() + i, nums.begin() + i + k);
        }
    }

    return res;
    }
};