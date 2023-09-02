class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for(auto dic:dictionary) {
            dict.insert(dic);
        }
        int n = s.length();
        vector<int> val(n,0);
        for(int i=0 ; i<n ; ++i) {  
            string t;
            for(int j=i ; j<n ; ++j) {
                t.push_back(s[j]);
                if(dict.find(t)!=dict.end()) {
                    val[j] = max((unsigned long)val[j],(i==0? 0 : val[i-1])+t.size());
                }
                else {
                    val[j] = max(val[j],(i==0? 0 : val[i-1]));
                }
            }
        }
        for(auto i:val) {
            cout << i << " ";
        }
        return n-val[n-1];
    }
};