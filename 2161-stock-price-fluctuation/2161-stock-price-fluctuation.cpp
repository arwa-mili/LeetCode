class StockPrice {
    priority_queue<int> pq_max;
    priority_queue<int,vector<int>, greater<int> > pq_min;
    unordered_map<int,int> freq;
    unordered_map<int,int> um;
    
    int max_ts,curr;
public:
    StockPrice() {
        max_ts = curr = 0;
    }
    
    void update(int ts, int price) {

        if(um.find(ts) != um.end()){         
            freq[um[ts]]--;
			
            while(!pq_max.empty() && freq[pq_max.top()] == 0){
                pq_max.pop();
            }
            while(!pq_min.empty() && freq[pq_min.top()] == 0){
                pq_min.pop();
            }
        }
        
        um[ts] = price;     
        
        if(freq[price]++ == 0){ 
            pq_max.push(price);
            pq_min.push(price);    
        }
        
        if(ts >= max_ts){ 
            max_ts = ts;
            curr = price;
        }
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return pq_max.top();
    }
    
    int minimum() {
        return pq_min.top();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */