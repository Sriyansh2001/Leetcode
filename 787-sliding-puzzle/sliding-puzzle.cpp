class Solution {
public:
    map<string,int> hashMap;
    int n = 2,m = 3;
    int tempi, tempj, temp;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    bool checkIsPass(vector<vector<int>> &board) {
        int start = 1;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(board[i][j] == start) {
                    start++;
                    if(start == 6) {
                        return true;
                    }
                } else return false;
            }
        }
        return true;
    }

    bool checkSwapPossible(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    string convertIntoString(vector<vector<int>> &board) {
        string s;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                s.push_back(board[i][j] + '0');
            }
        }
        return s;
    }

    void solve(vector<vector<int>> &board, int i,int j, int moves) {
        string currentBoard = convertIntoString(board);
        if(hashMap.find(currentBoard) != hashMap.end() && hashMap[currentBoard] < moves) {
            return ;
        }
        hashMap[currentBoard] = moves;
        for(auto d: dir) {
            int tempi = i+d[0];
            int tempj = j+d[1];
            if(checkSwapPossible(tempi,tempj)) {
                temp = board[i][j];
                board[i][j] = board[tempi][tempj];
                board[tempi][tempj] = temp;
                solve(board, tempi, tempj,moves + 1);
                temp = board[i][j];
                board[i][j] = board[tempi][tempj];
                board[tempi][tempj] = temp;
            }
        }
        return ;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<m ; ++j) {
                if(board[i][j] == 0) {
                    tempi = i;
                    tempj = j;
                }
            }
        } 
        solve(board,tempi,tempj,0);
        if(hashMap.find("123450") == hashMap.end()) {
            return -1;
        } return hashMap["123450"];
    }
};