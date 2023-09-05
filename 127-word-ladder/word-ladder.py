from collections import deque

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        freq = {}
        
        for i in wordList:
            freq[i]=False

        if(endWord not in freq):
            return 0

        q = deque()
        q.append(beginWord)
        count = 1
        freq[beginWord]=True
        while(q):
            size = len(q)
            while(size > 0):
                size-=1
                val = q.popleft()
                if(val == endWord):
                    return count
                for i in range(len(val)):
                    for j in range(26):
                        exp = val[0:i]+chr(97+j)+val[i+1:]
                        if ((exp) in freq and freq[exp] == False):
                            freq[exp]=True
                            q.append(exp)
            count+=1
        return 0   