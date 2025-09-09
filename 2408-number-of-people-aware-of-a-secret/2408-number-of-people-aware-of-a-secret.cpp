class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        vector<tuple<int,int,long long>> v;
        v.push_back(make_tuple(delay, forget, 1)); 
        
        for (int day = 2; day <= n; day++) {
            vector<tuple<int,int,long long>> survivors;
            long long newPeople = 0;
            
            for (auto &t : v) {
                int curDelay = get<0>(t);
                int curForget = get<1>(t);
                long long count = get<2>(t);
                
                if (curDelay > 0) {
                    curDelay--;
                }
                
                if (curDelay == 0 && curForget > 1) {
                    newPeople = (newPeople + count) % MOD;
                }
                
                curForget--;
                
                if (curForget > 0) {
                    survivors.push_back(make_tuple(curDelay, curForget, count));
                }
            }
            
            if (newPeople > 0) {
                survivors.push_back(make_tuple(delay, forget, newPeople));
            }
            
            v = survivors;
        }
        
        long long result = 0;
        for (auto &t : v) {
            result = (result + get<2>(t)) % MOD;
        }
        
        return result;
    }
};