class SeatManager {
public: 
    set<int> st1;

    SeatManager(int n) {
        for(int i=1 ; i<=n ; ++i) {
            st1.insert(i);
        }
    }
    
    int reserve() {
        int k = *st1.begin();
        st1.erase(k);
        return k;
    }
    
    void unreserve(int seatNumber) {
        st1.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */