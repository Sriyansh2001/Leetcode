class Solution {
public:
    vector<string> seperateOverSpace(string s1) {
        vector<string> res;
        string s;
        for(int i=0 ; i<s1.length() ; ++i) {
            if(s1[i] == ' ') {
                res.push_back(s);
                s = "";
            } else {
                s.push_back(s1[i]);
            }
        }
        res.push_back(s);
        return res;
    }

    int isEqualString(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        if(n  != m) return false;
        for(int i=0 ; i<n ; ++i) {
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = seperateOverSpace(sentence1);
        vector<string> s2 = seperateOverSpace(sentence2);
        int i1=0,j1=0;
        int i2=s1.size(),j2=s2.size();
        while(i1 < i2 && j1 < j2) {
            if(!isEqualString(s1[i1],s2[j1])) {
                break;
            }
            i1++;
            j1++;
        }
        if(i1 == i2 || j1 == j2) 
            return true;
        i1-=1;
        j1-=1;
        i2-=1;
        j2-=1;
        while(i2 >= 0 && j2 >= 0) {
            if(!isEqualString(s1[i2],s2[j2])) {
                break;
            }
            i2--;
            j2--;
        }
        if(i1 >= i2 || j1 >= j2) 
            return true;
        return false;
    }
};