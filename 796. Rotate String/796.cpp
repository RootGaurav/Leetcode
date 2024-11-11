class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return 0;
        return (s+s).find(goal) != string::npos;
    }
};