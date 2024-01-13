class Solution:
    def minSteps(self, m1: str, m2: str) -> int:
        s = Counter(m1)
        t = Counter(m2)
        ans=0
        for i in s:
            if i in t:
                ans += abs(s[i]-t[i])
                del t[i]
            else:
                ans += s[i]
        for i in t:
            if i in s:
                ans += abs(s[i]-t[i])
                del s[i]
            else:
                ans += t[i]
        return ans//2
                