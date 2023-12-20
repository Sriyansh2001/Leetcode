class Solution {
public:
    bool checkvowel(char s) {
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u');
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int vol,con,ans=0;
        for(int i=0 ; i<n ; ++i) {
            vol=con=0;
            for(int j=i ; j<n ; ++j) {
                if(checkvowel(s[j])) {
                    vol+=1;
                }else {
                    con+=1;
                }
                if(vol == con && (vol*con)%k == 0) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};