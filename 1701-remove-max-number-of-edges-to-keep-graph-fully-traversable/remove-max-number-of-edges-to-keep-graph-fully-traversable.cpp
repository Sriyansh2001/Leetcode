class DSU {
    vector<int> parent;
    int n;
public:
    DSU(int n) {
        parent.resize(n+1,-1);
        this->n = n+1;
    }

    int find(int i) {
        if(parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    bool join(int a,int b) {
        int f1 = find(a);
        int f2 = find(b);
        if(f1 == f2) {
            return false;
        }
        parent[f1] = f2;
        return true;
    }

    bool possible() {
        int count = 0;
        for(int i=1 ; i<n ; ++i) {
            if(parent[i] == -1) {
                count += 1;
            }
        }
        return count <= 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n),bob(n);
        int m = edges.size(),count = 0;
        for(int i=0 ; i<m ; ++i) {
            if(edges[i][0] == 3) {
                if(alice.join(edges[i][2],edges[i][1])) {
                    count += 1;
                    bob.join(edges[i][2],edges[i][1]);
                }
            }
        }
        for(int i=0 ; i<m ; ++i) {
            if(edges[i][0] == 2) {
                if(bob.join(edges[i][2],edges[i][1])) {
                    count += 1;
                }
            }
            else if(edges[i][0] == 1) {
                if(alice.join(edges[i][2],edges[i][1])) {
                    count += 1;
                }
            }
        }
        if(bob.possible() && alice.possible()) {
            return m-count;
        }
        return -1;
    }
};