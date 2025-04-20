class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> count;
        int res = 0;

        for (int a : answers) {
            if (count[a] == 0) {
                res += (a + 1); 
                count[a] = a;   
            } else {
                count[a]--;
            }
        }

        return res;
    }
};