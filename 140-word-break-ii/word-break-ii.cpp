class Trie {
    vector<Trie*> alp;
    bool end;
    const char startVal = 'a';
public:
    Trie() {
        alp.resize(26);
        for(int i=0 ; i<26 ; ++i) {
            this->alp[i]=NULL;
        }
        this->end = false;
    }

    void markEndTrue() {
        this->end = true;
    }

    void insert(string &word) {
        int size = word.length();
        Trie* currentPointer = this;
        for(int i=0 ; i<size ; ++i) {
            int currentIndex = word[i]-startVal;
            if(currentPointer->alp[currentIndex] == NULL) {
                currentPointer->alp[currentIndex] = new Trie();
            }
            currentPointer = currentPointer->alp[currentIndex];
        }
        currentPointer->markEndTrue();
    }

    bool checkStringAva(string s) {
        return testString(s,0,this);
    }

private:
    bool testString(string &s,int ind,Trie* container) {
        if(ind >= s.length()) return container->end;
        if(container->alp[s[ind] - startVal] == NULL) return false;
        return testString(s,ind+1,container->alp[s[ind] - startVal]);
    }
};

class Solution {
public:
    vector<string> ans;

    void solve(string &s,Trie* container,string &res,int i) {
        int size = s.length();
        if(i >= size) {
            ans.push_back(res);
            return ;
        }
        string curr="";
        int start = i;
        while(i<size) {
            res.push_back(s[i]);
            curr.push_back(s[i]);
            if(container->checkStringAva(curr)) {
                if(i != size-1) {
                    res.push_back(' ');
                }
                solve(s,container,res,i+1);
                if(i != size-1) {
                    res.pop_back();
                }
            }
            i+=1;
        }
        while(i > start) {
            res.pop_back();
            i-=1;
        }
    }
 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* container = new Trie();
        int n = wordDict.size();
        for(int i=0 ; i<n ; ++i) {
            container->insert(wordDict[i]);
        }
        string res;
        solve(s,container,res,0);
        return ans;
    }
};