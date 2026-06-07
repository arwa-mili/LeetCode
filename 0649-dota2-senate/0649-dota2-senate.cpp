class Solution {
public:
    string predictPartyVictory(string senate) {
        stack<char> waitingToBan;
        for (int i = 0; i < senate.size(); i++) {
            if (!waitingToBan.empty() && waitingToBan.top() != senate[i]) {
                senate += waitingToBan.top();
                waitingToBan.pop();
            } else {
                waitingToBan.push(senate[i]);
            }
        }
        return waitingToBan.top() == 'R' ? "Radiant" : "Dire";
    }
};