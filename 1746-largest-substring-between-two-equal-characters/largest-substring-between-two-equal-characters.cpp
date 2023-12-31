class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int start[26],end[26];
        for(int i=0 ; i<26 ; ++i) {
            start[i] = -1;
            end[i] = -1;
        }
        int n = s.length();
        for(int i=0 ; i<n ; ++i) {
            int ind = s[i]-'a';
            if(start[ind] == -1) {
                start[ind] = i;
            }
            end[ind] = i;
        }
        int ans = -1;
        for(int i=0 ; i<26 ; ++i) {
            if(start[i] != end[i]) {
                ans = max(ans,end[i]-start[i]-1);
            }
        }
        return ans;
    }
};