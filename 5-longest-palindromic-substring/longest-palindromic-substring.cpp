class Solution {
public:
    string longestPalindrome(string s) {
        string t = "";
        int n = s.length();
        for(int i=0 ; i<n ; ++i) {
            t.push_back(s[i]);
            t.push_back('#');
        }
        int ans = 0;
        string res="";
        for(int i=0 ; i<t.size() ; ++i) {
            int count = 0,a,b;
            if(t[i] == '#') {
                a=i-1,b=i+1;
                while(a >=0 && b < t.size()) {
                    if(t[a] == t[b]) {
                        count+=2;
                    }
                    else {
                        break;
                    }
                    a-=2; b+=2;
                }
            }
            else {
                a=i-2,b=i+2;
                count = 1;
                while(a >=0 && b < t.size()) {
                    if(t[a] == t[b]) {
                        count+=2;
                    }
                    else {
                        break;
                    }
                    a-=2; b+=2;
                }
            }
            if(ans < count) {
                string n="";
                a+=2;
                b-=2;
                for(int k=a ; k<=b ; k+=2) {
                    n.push_back(t[k]);
                }
                res = n;
                ans = count;
            }
        }
        return res;
    }
};