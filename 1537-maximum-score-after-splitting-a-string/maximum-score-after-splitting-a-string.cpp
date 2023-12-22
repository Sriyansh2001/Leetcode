class Solution {
public:
    int maxScore(string s) {
        int zero=0,one=0;
        int n = s.length();
        for(int i=1 ; i<n ; ++i) {
            if(s[i] == '1') {
                one+=1;
            }
        }
        if(s[0] == '0') zero+=1;
        int ans = 0;
        for(int i=1 ; i<n ; ++i) {
            ans = max(ans,zero+one);
            if(s[i] == '0') {
                zero+=1;
            }
            if(s[i]=='1') {
                one-=1;
            }
        }
        return ans;
    }
};