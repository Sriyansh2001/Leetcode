class Solution {
public:
    vector<vector<bool>> vis;
    int n,m;
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    bool solve(vector<vector<char>> &grid,int i,int j,char k,int previ,int prevj) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        if(grid[i][j]!=k) return false;
        if(vis[i][j]) return true;
        vis[i][j] = 1;
        bool res = false;
        for(auto d:dir) {
            int x = d[0]+i;
            int y = d[1]+j;
            if(x == previ && y == prevj) continue;
            res |= solve(grid,x,y,k,i,j);
        }
        return res;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool> (m,false));
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(!vis[i][j]) {
                    if(solve(grid,i,j,grid[i][j],-1,-1)) return true;
                }
            }
        }
        return false;
    }
};