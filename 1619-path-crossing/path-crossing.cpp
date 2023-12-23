class Solution {
public:
    bool isPathCrossing(string path) {
        set<string> st;
        int i=0,j=0;
        string str = to_string(i)+" "+to_string(j);
        st.insert(str);
        for(int k=0 ; k<path.length() ; ++k) {
            if(path[k] == 'N') j+=1;
            else if(path[k]=='S') j-=1;
            else if(path[k] == 'E') i+=1;
            else if(path[k] == 'W') i-=1;
            str = to_string(i)+" "+to_string(j);
            if(st.find(str) != st.end()) {
                return true;
            }
            st.insert(str);
        }
        return false;
    }
};