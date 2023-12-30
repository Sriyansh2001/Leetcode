class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int arr[26],n = words.size();
        for(int i=0 ; i<26 ; ++i) {
            arr[i] = 0;
        }
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<words[i].length() ; ++j) {
                arr[words[i][j]-'a'] += 1;
            }
        }
        for(int i=0 ; i<26 ; ++i) {
            if(arr[i]%n != 0) {
                return false;
            }
        }
        return true;
    }
};