class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        d1 = {}
        for i in word1:
            if i in d1:
                d1[i]+=1
            else:
                d1[i]=1
        d2 = {}
        for i in word2:
            if i in d2:
                d2[i]+=1
            else:
                d2[i]=1
        l1=[]
        l2=[]
        t1=[]
        t2=[]
        for i in d1:
            l1.append(d1[i])
            t1.append(i)
        for i in d2:
            l2.append(d2[i])
            t2.append(i)
        l1.sort()
        l2.sort()
        t1.sort()
        t2.sort()
        return l1==l2 and t1==t2