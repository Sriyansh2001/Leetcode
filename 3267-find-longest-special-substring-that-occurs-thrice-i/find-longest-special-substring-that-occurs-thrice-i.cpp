class Solution {
public:
    int maximumLength(string s) {
        map<string,int> mp;
        int n = s.length(), ans = 0;
        string k = "";
        for(int i=0 ; i<n ; ++i) {
            int m = k.length();
            if(m != 0 && k[m-1] != s[i]) {
                for(int j=0 ; j<m ; ++j) {
                    string t="";
                    for(int l=j ; l<m ; ++l) {
                        t.push_back(k[l]);
                        mp[t]++;
                        if(mp[t] >= 3) {
                            ans = max(ans, (int)t.length());
                        }
                    }
                }
                k = "";
            } 
            k.push_back(s[i]);
        }
        int m = k.length();
        for(int j=0 ; j<m ; ++j) {
            string t="";
            for(int l=j ; l<m ; ++l) {
                t.push_back(k[l]);
                mp[t]++;
                if(mp[t] >= 3) {
                    ans = max(ans, (int)t.length());
                }
            }
        }
        return ans ? ans : -1;
    }
};