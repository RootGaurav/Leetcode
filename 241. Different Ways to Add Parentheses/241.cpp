class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;

        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];

            if (c == '-' || c == '+' || c == '*') {
                string part1 = input.substr(0, i);
                string part2 = input.substr(i + 1);

                vector<int> part1Results = diffWaysToCompute(part1);
                vector<int> part2Results = diffWaysToCompute(part2);

                for (int x : part1Results) {
                    for (int y : part2Results) {
                        if (c == '-') {
                            result.push_back(x - y);
                        } else if (c == '+') {
                            result.push_back(x + y);
                        } else if (c == '*') {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(input));
        }

        return result;
    }
};