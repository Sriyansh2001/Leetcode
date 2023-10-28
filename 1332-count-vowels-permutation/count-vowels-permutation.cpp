class Solution {
public:
    unordered_map<string,int> mp;
    const int M = 1e9+7;
    int solve(char a,int n) {
        if(n==0) {
            return 1;
        }
        string key;
        key.push_back(a);
        key.append(to_string(n));
        if(mp.find(key)!=mp.end()) return mp[key];
        if(a=='a') {
            return mp[key] =  solve('e',n-1)%M;
        }
        if(a=='e') {
            return mp[key] =  (solve('a',n-1)+0LL+solve('i',n-1))%M;
        }
        if(a=='i') {
            return mp[key] =  (solve('a',n-1)+0LL+solve('e',n-1)+solve('u',n-1)+solve('o',n-1))%M;
        }
        if(a=='o') {
            return mp[key] =  (solve('i',n-1)+0LL+solve('u',n-1))%M;
        }
        if(a=='u') {
            return  mp[key] = solve('a',n-1)%M;
        }
        return -1;
    }
    
    int countVowelPermutation(int n) {
        string s="aeiou";
        long long ans = 0;
        for(int i=0 ; i<5 ; ++i) {
            ans = (ans+solve(s[i],n-1))%M;
        }
        return ans;
    }
};