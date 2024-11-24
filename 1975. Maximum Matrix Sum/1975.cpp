class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int c = 0;
        long long sum = 0;
        int min_element = abs(matrix[0][0]);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0){
                    c++;
                }
                sum += abs(matrix[i][j]);
                min_element = min(min_element,abs(matrix[i][j]));
            }
        }
        if(c%2 == 0){
           return sum;
        }
        else 
        return sum - 2*min_element;
    }
};