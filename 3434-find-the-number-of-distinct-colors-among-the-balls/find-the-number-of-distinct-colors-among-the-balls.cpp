class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> ballContainer, colorContainer;
        int n = queries.size();
        vector<int> ans;
        for(int i=0 ; i<n ; ++i) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballContainer.find(ball) != ballContainer.end()) {
                if(!--colorContainer[ballContainer[ball]]) {
                    colorContainer.erase(ballContainer[ball]);
                }
            }
            ballContainer[ball] = color;
            colorContainer[color]++;
            ans.push_back(colorContainer.size());
        }
        return ans;
    }
};