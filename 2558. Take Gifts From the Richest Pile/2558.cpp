class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
      priority_queue<int> ans;
      for(int i:gifts)
      {
        ans.push(i);
      } 
      int i=0;
      while (!ans.empty() && i<k) {
        i++;
        int j=sqrt(ans.top());
        ans.pop();
        ans.push(j);
       }
        long long sum=0;
        while (!ans.empty()) {
        sum+=ans.top();
        ans.pop();
       }
       return sum;
    }
};