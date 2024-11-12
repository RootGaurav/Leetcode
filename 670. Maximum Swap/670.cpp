class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        for(int i=0; i<s.length()-1; i++){
            int swap_index = i;
            for(int j=s.length()-1; j>i; j--){
                if(s[swap_index] < s[j]){
                    swap_index = j;
                }
            }
            if(swap_index != i){
                swap(s[swap_index], s[i]);
                return stoi(s);
            }
        }
        return num;
    }
};