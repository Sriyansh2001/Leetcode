class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def distance(a,b,x,y):
            return max(abs(a-x),abs(b-y))

        ans = 0
        for i in range(1,len(points)):
            ans += distance(points[i-1][0],points[i-1][1],points[i][0],points[i][1])
        return ans