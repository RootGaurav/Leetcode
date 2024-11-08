class Solution {
public:
    vector<int> getMaximumXor(vector<int>& v, int m) {
        for(int i=1;i<v.size();i++){
            v[i]=v[i]^v[i-1];
        }
int t=0;
int k=pow(2,m);
for(int i=0;i<k;i++){
t=max(t,i^v[v.size()-1]);
}
for(int i=v.size()-1;i>=0;i--){
    v[i]=v[i]^t;
}
reverse(v.begin(),v.end());

return v;
    }
};