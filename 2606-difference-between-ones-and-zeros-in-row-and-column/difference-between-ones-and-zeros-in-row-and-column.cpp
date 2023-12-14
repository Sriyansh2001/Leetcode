class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> rowOne(n,0),colOne(m,0);
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                rowOne[i] += grid[i][j];
                colOne[j] += grid[i][j];
            }
        }
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                ans[i][j] = (2*rowOne[i]-n)+(2*colOne[j]-m);
            }
        }
        return ans;
    }
};