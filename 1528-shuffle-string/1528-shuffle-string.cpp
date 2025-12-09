class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,string> m;
        int n = indices.size();
        string ans = "";

        for (int i =0;i<n;i++) {
            m[indices[i]] = s[i];

        }

        for (int i =0;i<n;i++) {
            ans.append(m[i]);

        }
        return ans;


         
        
    }
};