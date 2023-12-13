class Solution {
public:
    int specialCheck(vector<vector<int>> &mat,int i,int j) {
        int one = 0;
        int n = mat.size(),m = mat[0].size();
        for(int ind=0 ; ind<n ; ++ind) {
            if(mat[ind][j] == 1) {
                one += 1;
            }
        }
        for(int ind=0 ; ind<m ; ++ind) {
            if(mat[i][ind] == 1) {
                one += 1;
            }
        }
        return one == 2;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        int ans = 0;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(mat[i][j] == 1) {
                    if(specialCheck(mat,i,j)) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};