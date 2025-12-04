class Solution {
public:
    int countCollisions(string directions) {
        stack<int> s;
        int ans = 0;
        s.push(directions[0]);

        for (int i = 1; i < directions.size(); i++) {
            if (s.empty() or s.top() == directions[i]) {
                s.push(directions[i]);
                continue;
            }

            int temp = s.top();

            if (temp == 'L') {
                s.push(directions[i]);
            } else if (temp == 'S') {
                if (directions[i] == 'R')
                    s.push(directions[i]);
                else
                    ans++;
            } else {
                if (directions[i] == 'L') {
                    ans += 2;
                    s.pop();
                }
                while (!s.empty() and s.top() == 'R') {
                    ans++;
                    s.pop();
                }
                s.push('S');
            }
        }

        return ans;
    }
};