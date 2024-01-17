class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d = {}
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        st = list(set([i for i in d.values()]))
        if(len(st) != len(d)):
            return False
        return True