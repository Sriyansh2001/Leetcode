class Solution {
public:
    bool checkvowel(char a) {
        bool small = (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
        bool capital = (a=='A' || a=='E' || a=='I' || a=='O' || a=='U');
        return ( small || capital);
    }

    string sortVowels(string s) {
        int n = s.length();
        vector<int> index,alp;
        for(int i=0 ; i<n ; ++i) {
            if(checkvowel(s[i])) {
                alp.push_back(s[i]);
                index.push_back(i);
            }
        }
        sort(alp.begin(),alp.end());
        n = alp.size();
        for(int i=0 ; i<n ; ++i) {
            s[index[i]] = alp[i];
        }
        return s;
    }
};