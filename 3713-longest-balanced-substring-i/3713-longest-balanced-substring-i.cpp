class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<char, int> mp;
        int sz = s.size(), ans = 0;
        
        for(int i = 0; i < sz; i++) {
            mp = {}; 
            
            for(int j = i; j < sz; j++) {
                mp[s[j]]++;
                
                bool flag = true;
                int cnt = mp[s[j]];  
                
                for(auto x : mp) {
                    if(x.second != cnt) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};