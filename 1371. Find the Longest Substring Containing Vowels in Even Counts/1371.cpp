class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int mask = 0;
        int maxlength = 0;
        mp[0] = -1; 
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                mask ^= 1;
            else if (s[i] == 'e')
                mask ^= 2;
            else if (s[i] == 'i')
                mask ^= 4;
            else if (s[i] == 'o')
                mask ^= 8;
            else if (s[i] == 'u')
                mask ^= 16;

            if (mp.find(mask) != mp.end()) {
                int ind = mp[mask];
                maxlength = max(maxlength, i - ind);
            } else {
                mp[mask] = i;  
            }
        }
        return maxlength;
    }
};