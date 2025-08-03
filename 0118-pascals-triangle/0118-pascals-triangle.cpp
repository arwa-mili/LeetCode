class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> v;
        v.push_back({1}); 
        int k = 1;
        while(k<numRows) {
            vector<int> elem;
            elem.push_back(1); 
            for (int i =1;i< k;i++){
                elem.push_back(v[k - 1][i - 1] + v[k - 1][i]); 
            }
            elem.push_back(1);
            v.push_back(elem); 
            k += 1;
           
        }
        return v;
        
    }
};