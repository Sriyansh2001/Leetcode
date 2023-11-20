class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length(),black = 0;
        long long ans = 0;
        for(int i=n-1 ; i>=0 ; --i) {
            if(s[i] == '0') black += 1;
            if(s[i] == '1') ans += black;
        }
        return ans;
    }
};