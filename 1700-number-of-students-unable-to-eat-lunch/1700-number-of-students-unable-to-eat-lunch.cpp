class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q(deque<int>(students.begin(), students.end()));
        stack<int> st;
        
        for (int i = sandwiches.size() - 1; i >= 0; i--)
            st.push(sandwiches[i]);

        int rotations = 0;

        while (!q.empty() && rotations < q.size()) {

            if (q.front() == st.top()) {
                q.pop();
                st.pop();
                rotations = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }

        return q.size();
    }
};