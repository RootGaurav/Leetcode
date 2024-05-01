class Solution {
public:
    string reversePrefix(string word, char ch) {

        int s=0,e=word.length();
        while(word[s]!=ch)
        {
             s++;
             if(s>=e) return word;
        }
        e=s;
        s=0;
        while(s<=e)
        {
            swap(word[s++],word[e--]);
        }
        return word;
    }
};