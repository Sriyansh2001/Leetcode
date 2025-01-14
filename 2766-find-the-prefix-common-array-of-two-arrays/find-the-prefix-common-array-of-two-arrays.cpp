class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n,0);
        unordered_set<int> st1,st2;
        int total = n;
        for(int i=n-1 ; i>=0 ; --i) {
            res[i] = total;
            if(A[i] == B[i]) {
                total--;
            }
            else if(A[i] != B[i]) {
                if(st1.find(B[i]) == st1.end()) {
                    total--;
                } 
                if(st2.find(A[i]) == st2.end()) {
                    total--;
                }
            }
            st1.insert(A[i]);
            st2.insert(B[i]);
        }
        return res;
    }
};