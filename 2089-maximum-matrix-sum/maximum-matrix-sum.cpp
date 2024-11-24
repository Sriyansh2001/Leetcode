class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int noOfNegative = 0,n = matrix.size(), m = matrix[0].size(), minNumber = INT_MAX;
        long long res = 0;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(matrix[i][j] < 0) {
                    noOfNegative++;
                }
                int currentValue = abs(matrix[i][j]);
                minNumber = min(minNumber, currentValue);
                res += currentValue;
            }
        }
        if(noOfNegative & 1) {
            return res - 2*minNumber;
        }
        return res;
    }
};