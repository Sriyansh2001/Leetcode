class Solution {
public:
    int maxScore(string s) {
        int ones = 0,n=s.length(),zeros=0,ans=0;
        for(int i=0 ; i<n ; ++i) {
            if(s[i] == '1') {
                ones++;
            }
        }
        for(int i=0 ; i<n-1 ; ++i) {
            if(s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            ans = max(ans, ones+zeros);
        }
        return ans;
    }
};