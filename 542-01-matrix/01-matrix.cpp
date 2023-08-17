class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;

    bool valid(int i,int j) {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    bool border(vector<vector<int>> &mat,int i,int j) {
        int count = 0;
        for(int k=0 ; k<4 ; ++k) {
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(valid(x,y)) {
                if(mat[x][y] == 0) count+=1;
            }
        }
        return count>0;
    }

    void update(vector<vector<int>> &mat,vector<vector<int>> &ans,queue<pair<int,int>> &q) {
        int i,j;
        while(!q.empty()) {
            pair<int,int> top = q.front(); q.pop();
            i = top.first;
            j = top.second;
            for(auto k:dir) {
                int x = i+k[0];
                int y = j+k[1];
                if(valid(x,y) && mat[x][y] == 1 && ans[x][y] > ans[i][j]+1) {
                    ans[x][y] = ans[i][j]+1;
                    q.push({x,y});
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(mat[i][j] == 1 && border(mat,i,j)) { q.push({i,j}); ans[i][j]=1;}
                if(mat[i][j] == 0) ans[i][j] = 0;
            }
        }
        update(mat,ans,q);
        return ans;
    }
};