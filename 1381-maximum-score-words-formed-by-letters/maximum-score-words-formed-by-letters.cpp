class Solution {
public:
    int solve(vector<string> &words,map<char,int> &letters,vector<int> &score,int i) {
        if(i == words.size()) return 0;
        int n = words[i].size();
        int nonPick = solve(words,letters,score,i+1);
        int scoreVal = 0;
        for(int j=0 ; j<n ; ++j) {
            if(letters[words[i][j]] != 0) {
                letters[words[i][j]] -= 1;
                scoreVal += score[words[i][j]-'a'];
            } else {
                for(int k=0 ; k<j ; ++k) {
                    letters[words[i][k]]++;
                }
                return nonPick;
            }
        }
        int pick = solve(words,letters,score,i+1)+scoreVal;
        for(int j=0 ; j<n ; ++j) {
            letters[words[i][j]]++;
        }
        return max(pick, nonPick);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int> alp;
        for(auto i:letters) {
            alp[i]++;
        }
        return solve(words,alp,score,0);
    }
};