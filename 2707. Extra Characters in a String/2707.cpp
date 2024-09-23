class Solution {
public:
    int func(int ind, string &s, unordered_map<string, int> &mp, vector<int> &dp) {
    if (ind >= s.size()) return 0;  
    if (dp[ind] != -1) return dp[ind]; 
    int ans = 1 + func(ind + 1, s, mp, dp);  
    for (int j = ind; j < s.size(); j++) {
        if (mp[s.substr(ind, j - ind + 1)]) {  
            ans = min(ans, func(j + 1, s, mp, dp)); 
        }
    }

    return dp[ind] = ans;  
}

int minExtraChar(string s, vector<string> &dictionary) {
    unordered_map<string, int> mp;

    for (auto &x : dictionary) {
        mp[x]++;
    }

    vector<int> dp(s.size(), -1);

    return func(0, s, mp, dp);
}
};