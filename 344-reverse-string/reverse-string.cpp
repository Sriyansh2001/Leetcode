class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0 ; i<(s.size()/2) ; i++){
            char k = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = k;
        }
    }
};