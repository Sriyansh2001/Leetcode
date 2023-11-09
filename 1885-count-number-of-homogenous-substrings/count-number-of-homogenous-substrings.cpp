class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0,count;
        char c;
        int n = s.length();
        int i=0;

        while(i<n) {
            c = s[i];
            count = 0;
            while(i<n && s[i] == c) {
                i+=1;
                count += 1;
            }
            ans = ans + (count*(count+1))/2;
        }

        return ans%((int)1e9+7);
    }
};