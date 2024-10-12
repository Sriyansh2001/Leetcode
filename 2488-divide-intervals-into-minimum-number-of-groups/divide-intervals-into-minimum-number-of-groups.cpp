class Comparator {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
    static bool sortComparator(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

public:
    int minGroups(vector<vector<int>>& intervals) {
        int size = intervals.size();
        priority_queue<int, vector<int> , Comparator> q;
        sort(intervals.begin(), intervals.end(), sortComparator);
        q.push(intervals[0][1]);
        for(int i=1 ; i<size ; ++i) {
            int queueTop = q.top();
            if(queueTop < intervals[i][0]) {
                q.pop();
            }
            q.push(intervals[i][1]);
        }
        return q.size();
    }
};