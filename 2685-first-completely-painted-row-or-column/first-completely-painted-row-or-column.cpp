class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n,0), column(m,0);
        map<int,pair<int,int>> mp;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i=0 ; i<arr.size() ; ++i) {
            int rowIndex = mp[arr[i]].first;
            int colIndex = mp[arr[i]].second;
            row[rowIndex]++;
            column[colIndex]++;
            if(row[rowIndex] == m) {
                return i;
            } 
            if(column[colIndex] == n) {
                return i;
            }
        }
        return -1;
    }
};