class ProductOfNumbers {
public:
    vector<int> val;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        val.push_back(num);    
    }
    
    int getProduct(int k) {
        int n = val.size();
        int ans = 1;
        for(int j=n-1 ; j>=n-k ; --j) {
            ans *= val[j];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */