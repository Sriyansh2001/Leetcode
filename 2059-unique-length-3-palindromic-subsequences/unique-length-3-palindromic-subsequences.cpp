// TC -> O(26*N) , SC -> O(constant space).
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int start[26],end[26];
        bool found[26][26];
        int result = 0;
        // Initialize array.
        for(int i=0 ; i<26 ; ++i) {
            for(int j=0 ; j<26 ; ++j) {
                found[i][j] = 0;
            }
        }
        for(int i=0 ; i<26 ; ++i) {
            start[i] = -1;
            end[i] = -1;
        }
        //Finding the character that are between two similar character.
        for(int i=0 ; i<n ; ++i) { // -> O(N)
            if(start[s[i]-'a']==-1) {
                start[s[i]-'a'] = i;
                end[s[i]-'a'] = i;
            }
            else {
                for(int j=0 ; j<26 ; ++j) {   //  -> O(26*N)
                    if(end[j] > start[s[i]-'a']) {
                        found[s[i]-'a'][j] = 1;
                    }
                }
                end[s[i]-'a'] = i;
            }
        }
        //Count number of unique character.
        for(int i=0 ; i<26 ; ++i) {
            for(int j=0 ; j<26 ; ++j) {
                result += found[i][j];
            }
        }
        return result;
    }
};