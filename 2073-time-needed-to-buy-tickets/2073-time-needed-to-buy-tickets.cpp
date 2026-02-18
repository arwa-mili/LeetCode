class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int,int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }

        int total = 0;

        while (!q.empty()) {

            auto current = q.front();
            q.pop();

            current.first--;
            total++;

            if (current.second == k && current.first == 0) {
                return total;
            }

            if (current.first > 0) {
                q.push(current);
            }
        }

        return total;
    }
};
