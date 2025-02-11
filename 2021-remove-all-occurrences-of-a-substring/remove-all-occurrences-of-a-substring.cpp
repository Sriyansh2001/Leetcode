class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = s.length(), m = part.length();
        for(int i=0 ; i<n ; ++i) {
            res.push_back(s[i]);
            if(res.length() >= m) {
                int equal = true;
                int k = res.length();
                for(int j=m ; j>=0 ; --j) {
                    if(res[k] != part[j]) {
                        equal = false;
                        break;
                    }
                    k--;
                }
                if(equal) {
                    int l = m;
                    while(l!=0) {
                        res.pop_back();
                        l--;
                    }
                }
            }
        }
        return res;
    }
};