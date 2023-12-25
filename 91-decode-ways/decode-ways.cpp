class Solution {
public:
    int arr[101];
    int solve(string &s,int i) {
        if(i>=s.length()) return 1;
        if(s[i]=='0') return 0;
        if(arr[i]!=-1) return arr[i];
        int ans = 0;
        
        if(s[i]=='1') {
            if(i+1>=s.length()) {
                return 1;
            }
            return arr[i] = solve(s,i+2) + solve(s,i+1);
        }
        else if(s[i]=='2') {
            if(i+1>=s.length()) {
                return 1;
            }
            if(s[i+1] <= '6') {
                return arr[i] = solve(s,i+2) + solve(s,i+1);
            }
            else {
                return arr[i] = solve(s,i+1);
            }
        }
        else{
            return arr[i] = solve(s,i+1);
        }
        return 0;
    }
    
    int numDecodings(string s) {
        memset(arr,-1,sizeof(arr));
        return solve(s,0);
    }
};