class Solution {
public:
    char dp[101][101][27][101];
    int getLen(int n){
        if(n < 1) 
            return 0;
        if(n < 10)
            return 1;
        if(n < 100)
            return 2;
        return 3;
    }
    char call(int indx, int k, int last, int cum, string &s){
        if(indx == s.size())
            return getLen(cum) + (cum>1);
        char &ret = dp[indx][k][last][cum];
        if(~ret) return ret;
        int nextCum = last == (s[indx]-'a')? cum+1:1; 
        ret = call(indx+1, k, s[indx]-'a', nextCum, s) + (nextCum == 1?getLen(cum) + (cum>1):0);
        

        if(k)
            ret = min(ret, call(indx+1, k-1, last, cum, s)); 
		
        return ret;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return call(0, k, 26, 0, s);
    }
};