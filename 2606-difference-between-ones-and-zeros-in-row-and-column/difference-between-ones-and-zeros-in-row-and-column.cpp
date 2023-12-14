class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> rowOne(n,0),colOne(m,0),rowZero(n,0),colZero(m,0);
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                rowOne[i] += (grid[i][j] == 1);
                rowZero[i] += (grid[i][j] == 0);
                colOne[j] += (grid[i][j] == 1);
                colZero[j] += (grid[i][j] == 0);
            }
        }
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                ans[i][j] = rowOne[i]+colOne[j]-rowZero[i]-colZero[j];
            }
        }
        return ans;
    }
};