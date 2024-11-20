class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3, 0);
        for(char c: s){
            cnt[c-'a']++;
        }

        if(cnt[0] < k or cnt[1] < k or cnt[2] < k){
            return -1;
        }

        int left = 0;
        int right = 0;
        int window = 0;
        while(right < s.size()){
            cnt[s[right]-'a']--;

            while(left <= right and (cnt[0] < k or cnt[1] < k or cnt[2] < k)){
                cnt[s[left]-'a']++;
                left++;
            }

            window = max(window, right-left+1);
            right++;
        }

        return s.size() - window;
    }
};