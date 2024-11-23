class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for(int i=0 ; i<n ; ++i) {
            int startRock = 0;
            for(int j=0 ; j<m ; ++j) {
                if(box[i][j] == '.') {
                    char currentChar = box[i][j];
                    box[i][j] = box[i][startRock];
                    box[i][startRock] = currentChar;
                    startRock++;
                } else if(box[i][j] == '*') {
                    startRock = j+1;
                }
            }
         }
         vector<vector<char>> res(m, vector<char> (n,' '));
         for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                res[j][n-i-1] = box[i][j];
            } 
         } 
         return res;
    }
};