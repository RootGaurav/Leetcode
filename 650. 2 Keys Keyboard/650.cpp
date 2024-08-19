class Solution {
public:
    int minSteps(int targetCount) {
        if (targetCount == 1) return 0;
        vector<int> minOperations(targetCount + 1, INT_MAX);
        minOperations[1] = 0;
        
        for (int currentCount = 2; currentCount <= targetCount; currentCount++) {
            for (int factor = 1; factor * factor <= currentCount; factor++) {
                if (currentCount % factor == 0) {
                    minOperations[currentCount] = min(minOperations[currentCount], 
                                                      minOperations[factor] + currentCount / factor);
                    if (factor != currentCount / factor) {
                        minOperations[currentCount] = min(minOperations[currentCount], 
                                                          minOperations[currentCount / factor] + factor);
                    }
                }
            }
        }
        
        return minOperations[targetCount];
    }
};