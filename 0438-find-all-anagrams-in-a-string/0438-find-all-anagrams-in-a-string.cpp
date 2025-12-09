class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n =s.length();
        int m = p.length();
        

        vector<int> pCount(26,0) , sCount(26,0);
        vector<int> ans;

        for (char c: p){
            pCount[c - 'a']++;
        }

        for (int i =0; i<n;i++){
            sCount[s[i] - 'a']++;
            if(i>=m){
                sCount[s[i-m]-'a']--;
            }
            if (pCount == sCount) {
                ans.push_back(i-m+1);

            }
            
        }

        return ans;


        
    }
};