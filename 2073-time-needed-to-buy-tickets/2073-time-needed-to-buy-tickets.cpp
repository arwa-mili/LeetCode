class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<int> q;
        int res =0;
        for (int i =0; i< tickets.size(); i++) {
            q.push(i);
        }

        while (tickets[k] > 0) {
            int fr = q.front();
            q.pop();
            tickets[fr]--;
            res++;
            if (tickets[fr]) {
               q.push(fr);
            }


        }
        return res;
        
        
    }
};