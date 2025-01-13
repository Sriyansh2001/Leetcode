class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        for(int i=0 ; i<n ; ++i) {
            mp[s[i]]++;
        }
        int length = n;
        for(auto i:mp) {
            int count = i.second;
            if(count == 1 || count == 2) continue;
            if(count % 2 == 0) {
                length -= (count - 2);
            } else {
                length -= (count - 1);
            }
        }
        return length;
    }
};