class Solution {
public:
    vector<string> ls;
    string def = "abc";

    void solve(string &s, int n) {
        if(n == 0) {
            ls.push_back(s);
            return;
        }
        int k = s.length();
        for(int i=0 ; i<3 ; ++i) {
            if(s[k-1] != def[i]) {
                s.push_back(def[i]);
                solve(s,n-1);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        for(int i=0 ; i<3 ; ++i) {
            string s;
            s.push_back(def[i]);
            solve(s,n-1);
        }
        if(ls.size() < k) return "";
        return ls[k-1];
    }
};