class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length(),count=0,ans=0;
        for(int i=0 ; i<n ; ++i) {
            if(s[i] == '(') {
                count++;
            } else {
                if(count == 0) {
                    ans++;
                } else {
                    count--;
                }
            }
        }
        return ans + count;
    }
};