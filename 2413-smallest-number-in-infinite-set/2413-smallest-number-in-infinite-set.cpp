class SmallestInfiniteSet {
public:

    set<int> integers;
    int smallest=0;
    SmallestInfiniteSet() {
        smallest =1;
    }
  
    
    int popSmallest() {
        if (integers.empty()){
             
             long ans = smallest;
             smallest +=1;
             return ans;
        }
        auto it = integers.begin();
        long ans = *it;
        integers.erase(it);
        return ans ; 
        }
    
    void addBack(int num) {
        if (num >= smallest){
             return;
        }
        integers.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */