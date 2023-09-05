class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [-1 for i in range(n+1)]

        def solve(n):
            if(n == 0):
                return 0
            if(dp[n]!=-1):
                return dp[n]
            i=1
            ans = int(1e10)
            while(i*i <= n):
                ans = min(ans,solve(n-(i*i))+1)
                i+=1
            dp[n] = ans
            return ans
        
        return solve(n)
