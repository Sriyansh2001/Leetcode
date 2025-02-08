class NumberContainers {
public:
    map<int,set<int>> mp;
    map<int,int> indexMp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexMp.find(index) != indexMp.end()) {
            int num = indexMp[index];
            mp[num].erase(index);
            if(mp[num].size() == 0) {
                mp.erase(num);
            }
        }
        indexMp[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end()) return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */