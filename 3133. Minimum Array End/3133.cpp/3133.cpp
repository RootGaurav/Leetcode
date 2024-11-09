class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x, mask = 1;
        vector<int>ind;
        for(int i = 0; i < 63; i++){
            if(res >> i & mask ^ mask){
                ind.push_back(i);
            }
        }
        int size = ind.size();
        for(long long i = 0; i < (mask << size); i++){
            if(--n == 0){
                for(int j = 0; j < 63; j++){
                    if(i >> j & mask){
                        res |= mask << ind[j];
                    }
                }
                return res;
            }
        }
        return res;
    }
};